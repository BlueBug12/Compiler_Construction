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
	static int foo=0;
	static bool var_flag=0;
	static bool left_value_error=0;
    typedef struct symbol_table stb;

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

	char* find_type(char* id,int* line);
	/*initialize the head of symbol table*/
	stb* tail = NULL;
	
	char _type [9];
	char _var [128];
	char _etype [7];
%}

%error-verbose
//%define parse.error verbose
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
//%token COMMA
//%token QUOTA
%token NEWLINE

/*Arithmetic, relational, and logical operator*/
%token ADD SUB MUL QUO REM INC DEC //arithmetric
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
%type <string> Type TypeName ArrayType PrintType Operand /*Binary_op*/
%type <string> ConversionExpr PrimaryExpr UnaryExpr Literal IndexExpr Expression
%type <string> B1 B2 B3 B4 Add_op Mul_op Cmp_op Unary_op Assign_op LA LO ExpressionVar

%left ADD SUB
%left MUL QUO
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
		_type[0]='a';
		strncpy(_type+1,$1,strlen($1));
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
/*Expressions*/


Expression 
    : Expression LO B1{


		if(!strcmp($1,"unknown")||!strcmp($1,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($1,"float32")||!strcmp($3,"float32")){	
			printf("error:%d: invalid operation: (operator LOR not defined on float32)\n",yylineno);
		}
		else if(!strcmp($1,"int32")||!strcmp($3,"int32")){		
			printf("error:%d: invalid operation: (operator LOR not defined on int32)\n",yylineno);
		}
		
		$$="bool";	
		printf("%s\n",$2);
	}
	| B1{$$=$1;}
;
B1
	:B1 LA B2{


		if(!strcmp($1,"unknown")||!strcmp($3,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($1,"float32")||!strcmp($3,"float32")){	
			printf("error:%d: invalid operation: (operator LAND not defined on float32)\n",yylineno);
		}
		else if(!strcmp($1,"int32")||!strcmp($3,"int32")){		
			printf("error:%d: invalid operation: (operator LAND not defined on int32)\n",yylineno);
		}
		
		
		else if(strcmp($1,$3)){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
		}
		$$="bool";
		printf("%s\n",$2);
	}
	|B2{$$=$1;}
;
B2
	:B2 Cmp_op B3{

		if(!strcmp($1,"unknown")||!strcmp($3,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp($1,$3)){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
		}
		$$="bool";
		printf("%s\n",$2);
	}
	|B3{$$=$1;}
;
B3
	:B3 Add_op B4{

		if(!strcmp($1,"unknown")||!strcmp($3,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp($1,$3)){
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
			$$="float32";//conversion
		}
		$$=$1;
		printf("%s\n",$2);
	}
	|B4{$$=$1;}
;
B4
	:B4 Mul_op UnaryExpr{	


		if(!strcmp($1,"unknown")||!strcmp($3,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($2,"REM")&&(!(strcmp($1,"float32"))||!(strcmp($3,"float32")))){	
			printf("error:%d: invalid operation: (operator REM not defined on float32)\n",yylineno);
		}
		else if(strcmp($1,$3)){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
			$$="float32";//conversion
		}
		$$=$1;
		printf("%s\n",$2);
	}
	|UnaryExpr{$$=find_type($1,&foo);}
;
UnaryExpr 
    : PrimaryExpr{$$=$1;} 
    | Unary_op UnaryExpr{$$=$2;printf("%s\n",$1);}
;

LA
	:LAND{$$="LAND";}
;
LO
	:LOR{$$="LOR";}

Cmp_op 
    : EQL{$$="EQL";} 
    | NEQ{$$="NEQ";}
	| LSS{$$="LSS";}               
    | LEQ{$$="LEQ";}               
    | GTR{$$="GTR";}               
    | GEQ{$$="GEQ";}
;

Add_op 
    : ADD{$$="ADD";}
	| SUB{$$="SUB";}
;

Mul_op 
    : MUL{$$="MUL";}
    | QUO{$$="QUO";}
    | REM{$$="REM";}
;

Unary_op 
    : ADD{$$="POS";}
    | SUB{$$="NEG";}
    | NOT{$$="NOT";}
;

/*Primary expression*/
PrimaryExpr
    : Operand{$$=$1;}
    | IndexExpr{$$=$1;}
    | ConversionExpr{$$=$1;}
;

Operand
    : Literal{$$=$1;}
    | IDENT{lookup_symbol($1,tail);$$=find_type($1,&foo);var_flag=1;}
	| LPAREN  Expression RPAREN{$$=$2;}
;

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
    : PrimaryExpr LBRACK Expression RBRACK{$$=$1;}//need to be checked
;

/*Coversion (type casting)*/
ConversionExpr
     : Type LPAREN Expression RPAREN{$$=$1;printf("%c to %c\n",toupper($3[0]),toupper($1[0]));}
;

/*Statements*/
Statement
    : DeclarationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
;

SimpleStmt
    : AssignmentStmt{var_flag=0;}
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
    |
;

/*Assignments statements*/
AssignmentStmt 
    : ExpressionVar Assign_op Expression{	
		if(!strcmp($1,"unknown")||!strcmp($1,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($2,"REM_ASSIGN")&&(!strcmp($1,"float32")||!strcmp($3,"float32"))){	
			printf("error:%d: invalid operation: (operator REM_ASSIGN not defined on float32)\n",yylineno);
		}
		else if(strcmp($1,$3)){
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
		}
		else if(left_value_error){

			printf("error:%d: cannot assign to %s\n",yylineno,$1);
			left_value_error=0;
		}
		printf("%s\n",$2);
	}
;

ExpressionVar
	: Expression{
		if(!var_flag){
			
			left_value_error=1;
			var_flag=0;
		}
		$$=$1;
	}
;
Assign_op
    : ASSIGN {$$="ASSIGN";}
    | ADD_ASSIGN {$$="ADD_ASSIGN";}
    | SUB_ASSIGN {$$="SUB_ASSIGN";}
    | MUL_ASSIGN {$$="MUL_ASSIGN";}
    | QUO_ASSIGN {$$="QUO_ASSIGN";}
    | REM_ASSIGN {$$="REM_ASSIGN";}
;

/*IncDec statements*/
IncDecStmt
    : Expression IncDec
;

IncDec
    : INC{printf("INC\n");}
    | DEC{printf("DEC\n");}
;

/*Block*/
Block
    : LBRACE{++scope;} StatementList{dump_symbol(tail);} RBRACE{--scope;}
;


/*If statements* {stack(&stack_top,"#");}*/
IfStmt
    : IF Condition Block
	| IF Condition Block ELSE IfStmt
	| IF Condition Block ELSE Block
;

Condition
    : Expression{
		if(strcmp($1,"bool")){
			printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,$1);
		}
	}
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
	: PrintType LPAREN Expression RPAREN{printf("%s %s\n",$1,$3);}
;   

PrintType
    : PRINT{$$="PRINT";}
    | PRINTLN{$$="PRINTLN";}
;
%%
/* C code section */

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


char* find_type(char* id,int* line){
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
		char* t;
		if(!strcmp(temp->type,"array")){
			t=malloc(sizeof(*(temp->element_type)));
			strcpy(t,temp->element_type);
		}
		else{
			t=malloc(sizeof(*(temp->type)));
			strcpy(t,temp->type);
		}
		*line=temp->lineno;
		return t;
	}
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
	

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
		int* pre_line=malloc(sizeof(int));
		if(strcmp(find_type(id,pre_line),"unknown")){
			printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,id,*pre_line);
			return;	
		}
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
	printf("error:%d: undefined: %s\n",yylineno+1,id);
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
