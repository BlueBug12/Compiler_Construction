/*Definition section */
%{
    #include <stdio.h>	
    #include <stdbool.h>
    #include <string.h>
	#include <ctype.h>
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
	
	static int scope=0;	
    static int address=-1;
    typedef struct symbol_table stb;
	typedef struct operator_stack op_stack;

    struct symbol_table{
		int index;
		char* name;
		char* type;
		int address;
		int lineno;
		int scope;
		char* element_type;	
		//stb* next;
		stb* prev;
		stb* child;
		stb* last_child;
    };

	struct operator_stack{
		char* op;
		op_stack* prev;
		op_stack* next;
	};

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(char* id,char* type, char* etype);
    static void insert_symbol(stb* n);
    static void lookup_symbol(char*id,stb* n);
    static void dump_symbol(stb* n);
	
	stb* new_stb_node(int index,char* name, char* type,
						char* element_type,stb* prev,stb*child,stb* last_child);
	int precedence(char* op,bool in_stack);
	void push(char* op,op_stack**top);
	char* pop(op_stack** top);	
	void stack(op_stack** top,char* op);
	char* find_type(char* id);
	/*initialize the head of symbol table*/
	//stb* head = NULL;
	stb* tail = NULL;
	
	op_stack* stack_top=NULL;
	char _type [9];
	char _var [128];
	char _etype [7];
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char* string;
    bool b_val;
}

/* Token without return */
/*Delimiters*/
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE //parentheses
%token SEMICOLON
%token COMMA
%token QUOTA
%token NEWLINE

/*Arithmetic, relational, and logical operator*/
%token ADD SUB MUL QUO MOD INC DEC REM POS NEG//arithmetric
%token LSS GTR LEQ GEQ EQL NEQ //relational
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN //assignment
%token LAND LOR NOT TRUE FALSE//logical

/*Keywords*/
//%token INT FLOAT BOOL STRING //data type
%token IF ELSE FOR //conditional
%token VAR //variable declaration
%token PRINT PRINTLN

/* Token with return, which need to sepcify type */
%token <string> IDENT
%token <string> INT FLOAT BOOL STRING
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <string> STRING_LIT
%token <b_val> BOOL_LIT
/* Nonterminal with return, which need to sepcify type */
%type <string> Type TypeName ArrayType PrintType Operand Binary_op
%type <string> ConversionExpr PrimaryExpr UnaryExpr Literal IndexExpr Expression
%type <string> B1 B2 B3 B4
/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList
;

StatementList
    : StatementList Statement
    | Statement
;

/*Types*/
Type 
    : TypeName{$$=$1;}
    | ArrayType{
		//$$="array";
		_type[0]='a';
		//printf("test  %d cececcec\n",strlen($1));
//		strcpy(_etype,$1);
		strncpy(_type+1,$1,strlen($1));
		//printf("test    %s!!!!!!!!11\n",_type);
		$$=_type;
	}
;

TypeName 
    : INT {$$=$1;}
    | FLOAT {$$=$1;}
    | STRING {$$=$1;}
    | BOOL {$$=$1;}
;

ArrayType 
    :  LBRACK  Expression RBRACK Type{$$=$4;}
;
LBR
	:LBRACK{stack(&stack_top,"[");}
RBR
	:RBRACK{stack(&stack_top,"]");}
/*Expressions*/
/*
Expression 
    : UnaryExpr {$$=$1;}
    | Expression Binary_op Expression{$$=$2;}//error detect
;*/

Expression 
    : Expression Cmp_op B1{$$="bool";}//error detect
	| B1{$$=$1;}
;
B1
	:B1 LOR{stack(&stack_top,"LOR");} B2{$$="bool";}
	|B2{$$=$1;}
;
B2
	:B2 LAND{stack(&stack_top,"LAND");} B3{$$="bool";}
	|B3{$$=$1;}
;
B3
	:B3 Add_op B4{
		if(strcmp($1,$3))
			$$="float32";//conversion
		else
			$$=$1;
	}
	|B4{$$=$1;}
;
B4
	:B4 Mul_op UnaryExpr{	
		if(strcmp($1,$3))
			$$="float32";//conversion
		else
			$$=$1;
	}
	|UnaryExpr{$$=find_type($1);}
;
UnaryExpr 
    : PrimaryExpr{$$=$1;} 
    | Unary_op UnaryExpr{$$=$2;}
;
/*
Binary_op
    : LOR{stack(&stack_top,"LOR");$$="bool";} 
    | LAND{stack(&stack_top,"LAND");$$="bool";}
    | Cmp_op{$$="bool";} 
    | Add_op{$$="unknown";}
    | Mul_op{$$="unknown";}
;*/

Cmp_op 
    : EQL{stack(&stack_top,"EQL");} 
    | NEQ{stack(&stack_top,"NEQ");}
    | LSS{stack(&stack_top,"LSS");}
    | LEQ{stack(&stack_top,"LEQ");}
    | GTR{stack(&stack_top,"GTR");}
    | GEQ{stack(&stack_top,"GEQ");}
;

Add_op 
    : ADD{stack(&stack_top,"ADD");}
    | SUB{stack(&stack_top,"SUB");}
;

Mul_op 
    : MUL{stack(&stack_top,"MUL");}
    | QUO{stack(&stack_top,"QUO");}
    | REM{stack(&stack_top,"REM");}
;

Unary_op 
    : ADD{stack(&stack_top,"POS");}
    | SUB{stack(&stack_top,"NEG");}
    | NOT{stack(&stack_top,"NOT");}
;

/*Primary expression*/
PrimaryExpr
    : Operand{$$=$1;}
    | IndexExpr{$$=$1;}
    | ConversionExpr{$$=$1;}
;

Operand
    : Literal{$$=$1;}
    | IDENT{lookup_symbol($1,tail);$$=$1;}
	| LPA  Expression RPA{$$=$2;}
    //| LPAREN{stack(&stack_top,"(");}  Expression{$$=$2;} RPAREN{stack(&stack_top,")");}
;
LPA
	:LPAREN{stack(&stack_top,"(");}
RPA
	:RPAREN{stack(&stack_top,")");}
Literal
    : INT_LIT{printf("INT_LIT %d\n",$1);$$="int32";}
    | FLOAT_LIT{printf("FLOAT_LIT %f\n",$1);$$="float32";}
    | BOOL_LIT{printf("BOOL_LIT %d\n",$1);$$="bool";}
    | STRING_LIT{printf("STRING_LIT %s\n",$1);$$="string";} 
	| TRUE{printf("TRUE\n");$$="bool";}
	| FALSE{printf("FALSE\n");$$="bool";}
;

/*Index expression*/
IndexExpr
    : PrimaryExpr LBR Expression RBR{$$=$1;}//need to be checked
;

/*Coversion (type casting)*/
ConversionExpr
     : Type LPAREN Expression RPAREN{$$=$1;printf("%c to %c\n",toupper($3[0]),toupper($1[0]));}
;

/*Statements*/
Statement
    : DeclarationStmt NEWLINE{stack(&stack_top,"#");}
    | SimpleStmt NEWLINE{stack(&stack_top,"#");}
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
;

SimpleStmt
    : AssignmentStmt
    | Expression
    | IncDecStmt
;

/*Declarations statements*/
DeclarationStmt 
    : VAR IDENT Type DeclarationAssign{
		strcpy(_var,$2);

		if($3[0]=='a'){
			create_symbol(_var,"array",_type+1);				
		}
		else{
			strcpy(_type,$3);
			create_symbol(_var,_type,"-");				
		}
	}
;

DeclarationAssign
    : ASSIGN Expression
    | /*empty*/
;

/*Assignments statements*/
AssignmentStmt 
    : Expression Assign_op Expression
;

Assign_op
    : ASSIGN {stack(&stack_top,"ASSIGN");}
    | ADD_ASSIGN {stack(&stack_top,"ADD_ASSIGN");}
    | SUB_ASSIGN {stack(&stack_top,"SUB_ASSIGN");}
    | MUL_ASSIGN {stack(&stack_top,"MUL_ASSIGN");}
    | QUO_ASSIGN {stack(&stack_top,"QUO_ASSIGN");}
    | REM_ASSIGN {stack(&stack_top,"REM_ASSIGN");}
;

/*Expression statements*/
ExpressionStmt
    : Expression
;

/*IncDec statements*/
IncDecStmt
    : Expression IncDec
;

IncDec
    : INC
    | DEC
;

/*Block*/
Block
    : LBRACE{++scope;} StatementList{dump_symbol(tail);} RBRACE{--scope;}
;

StatementList
    :  StatementList Statement 
    |/*empty*/  
;

/*If statements*/
IfStmt
    : IF Condition{stack(&stack_top,"#");} Block ElseIfStmt
;

Condition
    : Expression
;

OptionalIfStmt
    : IfStmt
    | Block
;

ElseIfStmt
    : ElseIfStmt ELSE OptionalIfStmt
    |/*empty*/
;


/*For statements*/
ForStmt
    : FOR ForCondition Block
;

ForCondition
    : Condition
    | ForClause
;

ForClause
    : InitStmt SEMICOLON Condition SEMICOLON PosStmt
;

InitStmt
    : SimpleStmt
;

PosStmt
    : SimpleStmt
;

/*Print statements*/
PrintStmt
    : PrintType LPAREN Expression RPAREN{stack(&stack_top,"#");printf("%s %s\n",$1,$3);}
;

PrintType
    : PRINT{$$="PRINT";}
    | PRINTLN{$$="PRINTLN";}
;
%%
/* C code section */
int precedence(char* op,bool in_stack){
	if(!strcmp(op,"(")&&in_stack==0)
		return 0;
	else if(!strcmp(op,"[")&&in_stack==0)
		return 1;
	else if(!strcmp(op,"POS")||!strcmp(op,"NEG")||!strcmp(op,"NOT"))
		return 2;
	else if(!strcmp(op,"MUL")||!strcmp(op,"QUO")||!strcmp(op,"REM"))
		return 3;
	else if(!strcmp(op,"ADD")||!strcmp(op,"SUB"))
		return 4;
	else if(!strcmp(op,"LSS")||!strcmp(op,"GTR")||!strcmp(op,"LEQ")||!strcmp(op,"GEQ")||!strcmp(op,"EQL")||!strcmp(op,"NEQ"))
		return 5;
	else if(!strcmp(op,"LAND"))
		return 6;
	else if(!strcmp(op,"LOR"))
		return 7;
	else if(!strcmp(op,"ASSIGN")||!strcmp(op,"ADD_ASSIGN")||!strcmp(op,"SUB_ASSIGN")||!strcmp(op,"MUL_ASSIGN")||!strcmp(op,"QUO_ASSIGN")||!strcmp(op,"REM_ASSIGN"))
		return 8;
	else if(!strcmp(op,"(")||!strcmp(op,"[")||!strcmp(op,"{"))
		return 9;
	else{
		printf("Error: unexpected operator in operator stack!\n");
		return -1;
	}
}
stb* new_stb_node(int index,char* name, char* type,
						char* element_type,stb* prev,stb*child,stb* last_child){
	stb* node = malloc(sizeof(stb));
	node->index=index;
	node->name=malloc(sizeof(name));
	strcpy(node->name,name);
	
	node->type=malloc(sizeof(type));
	strcpy(node->type,type);

	node->address=++address;
	node->scope=scope;
	node->element_type=malloc(sizeof(element_type));
	strcpy(node->element_type,element_type);

	node->lineno=yylineno;
	node->prev=prev;
	node->child=child;
	node->last_child=last_child;
	return node;
}

void test(op_stack* ptr){
	printf("stack: ");
	while(ptr!=NULL){
		printf("%s ",ptr->op);
		ptr=ptr->prev;
	}
	printf("\n");
}
void push(char* op, op_stack** top){
	op_stack* temp=malloc(sizeof(op_stack));
	temp->op=malloc(sizeof(op));
	strcpy(temp->op,op);
	temp->prev=*top;
	*top = temp;
}
char* pop(op_stack** top){
	if((*top)!=NULL){
		char* op=malloc(sizeof((*top)->op));
		strcpy(op,(*top)->op);
		op_stack* temp = (*top)->prev;
		free(*top);
		*top = temp;; 
		return op;
	}
	else{
		printf("Error: pop an empty operator stack!\n");
		return 0;
	}
}
void stack(op_stack** top,char* op){
	if(!strcmp("(",op)||!strcmp("[",op)||!strcmp("{",op))
		push(op,top);
	else if(!strcmp(")",op)){
		while((*top)!=NULL&&strcmp((*top)->op,"(")){
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
			
		}
		if((*top)==NULL){printf("NO match LPARN\n");}
		free(pop(top));
	}
	else if(!strcmp("]",op)){	
		while(strcmp((*top)->op,"[")){
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
		}
		free(pop(top));
	}
	
	else if(!strcmp("}",op)){	
		while(strcmp((*top)->op,"{")){
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
		}
		free(pop(top));
	}
	else if(!strcmp("#",op)){//clean all operator
		while((*top)!=NULL){	
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
		}
	}
	else if(!strcmp("NOT",op)){push(op,top);}
	else if((*top)==NULL||precedence(op,0)<precedence((*top)->op,1)){
		push(op,top);
	}
	
	else{
		do{	
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
		}while((*top)!=NULL&&precedence(op,0)>=precedence((*top)->op,1));
		push(op,top);
	}
}

char* find_type(char* id){
	if(!strcmp(id,"int32")||!strcmp(id,"float32")||!strcmp(id,"string")||!strcmp(id,"bool"))
		return id;
	stb* temp= tail;
	while(temp!=NULL&&strcmp(temp->name,id)){
		temp=temp->child;
	}
	if(temp==NULL){
		//printf("Error: find ID in empty stack!\n");
		return "unknown";
	}
	else{
		//char* t;
		if(!strcmp(temp->type,"array")){
			//t=malloc(sizeof(temp->element_type));
			strcpy(_type,temp->element_type);
		}
		else{
			//printf("find type: %s\n",temp->type);	
			//char* t=malloc(sizeof(temp->type));
			strcpy(_type,temp->type);
		}
		return _type;
	}
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
	
	//head = new_stb_node(0,"","","",NULL,NULL,NULL,head);
	//tail = head;

	//stack_top = malloc(sizeof(op_stack));
	//stack_top =NULL;
	//push("#",&stack_top);

    yylineno = 0;
    yyparse();
	dump_symbol(tail);
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(char* id, char* type, char* etype){

	if(tail==NULL||tail->scope!=scope){//empty symbol table or new scope
		stb* n=new_stb_node(0,id,type,etype,tail,NULL,NULL);
		n->last_child=n;
		tail=n;
		insert_symbol(n);
	}
	else{
		stb* n=new_stb_node(tail->last_child->index+1,id,type,etype,NULL,NULL,NULL);
		tail->last_child->child=n;
		tail->last_child=n;
		insert_symbol(n);	
	}
}

static void insert_symbol(stb* n) {
	
    printf("> Insert {%s} into symbol table (scope level: %d)\n", n->name, scope);
}

static void lookup_symbol(char* id, stb* n) {
	while(n!=NULL){
		if(!strcmp(id,n->name)){
			printf("IDENT (name=%s, address=%d)\n",n->name,n->address);
			return;
		}
		else
			n=n->child;
	}
	printf("Can't find the target ID!\n");
	return ;
}

static void dump_symbol(stb* n) {
    printf("> Dump symbol table (scope level: %d)\n", scope);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
	if(tail==NULL||tail->scope!=scope)return;
	stb* pretail=tail->prev;
	stb* temp=tail;
	while(tail!=NULL){
		
    	printf("%-10d%-10s%-10s%-10d%-10d%s\n",
			tail->index,tail->name,tail->type,tail->address,tail->lineno,tail->element_type);
		temp=tail;
		tail=tail->child;
		free(temp);
	}
    tail=pretail;
}
