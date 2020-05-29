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
	static bool foo_b=0;
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
    static int create_symbol(char* id,char* type, char* etype);//return register address
    static void insert_symbol(stb* n);
    static int lookup_symbol(char*id,stb* n);
    static void dump_symbol(stb* n);
	
	stb* new_stb_node(int index,char* name, char* type,
						char* element_type,stb* prev,stb*child,stb* last_child);

	char* find_type(char* id,int* line,bool* is_array);//need to merge with lookup_symbol
	char* lower_str(char* str);
	char* lower_substr(char* str, int len);
	/*initialize the head of symbol table*/
	stb* tail = NULL;
	//char* dict(const char* instruction);
	/*Global variables*/	
	char _type [9];
	char _var [128];
	char instruction[10];
	bool HAS_ERROR = false;
	bool l_array=0;
	int l_address=-1;
	int cmp_number=0; 
	//int if_number=0;
	//int if_exit_number=0;
	//int for_number=0;
	int* if_num;//at most 30 nested if statement
	int* if_exit_num;
	int* for_num;//at most 30 nested for statement
	FILE *file;
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
%token ADD SUB MUL DIV REM INC DEC //arithmetric
%token LSS GTR LEQ GEQ EQL NEQ //relational
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN //assignment
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
%type <string> B1 B2 B3 B4 Add_op Mul_op Cmp_op Unary_op Assign_op LA LO ExpressionVar IncDec
%type <b_val> DeclarationAssign 
//%left ADD SUB
//%left MUL DIV
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
		char* temp = lower_substr($1,strlen($1)-2);
		fprintf(file,"\tnewarray %s\n",temp);
		free(temp);
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
			HAS_ERROR=1;
		}
		else if(!strcmp($1,"int32")||!strcmp($3,"int32")){		
			printf("error:%d: invalid operation: (operator LOR not defined on int32)\n",yylineno);
			HAS_ERROR=1;
		}
		
		$$="bool";	
		printf("%s\n",$2);
		char* temp=lower_str($2+1);
		fprintf(file,"\ti%s\n",temp);
		free(temp);
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
			HAS_ERROR=1;
		}
		else if(!strcmp($1,"int32")||!strcmp($3,"int32")){		
			printf("error:%d: invalid operation: (operator LAND not defined on int32)\n",yylineno);
			HAS_ERROR=1;
		}
		
		
		else if(strcmp($1,$3)){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
			HAS_ERROR=1;
		}
		$$="bool";
		printf("%s\n",$2);
		char* temp=lower_str($2+1);
		fprintf(file,"\ti%s\n",temp);
		free(temp);
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
			HAS_ERROR=1;
		}
		$$="bool";
		if($1[0]=='i'){//int type
			fprintf(file,"\tisub\n");
		}
		else{//float type
			fprintf(file,"\tfcmpl\n");
		}
		if(!strcmp($2,"LSS"))
			fprintf(file,"\tiflt ");
		else{				
			char* temp = lower_substr($2,2);
			fprintf(file,"\tif%s ",temp);
			free(temp);		
		}
		fprintf(file,"L%d_cmp_%d\n\ticonst_0\n",scope,cmp_number++);
		fprintf(file,"\tgoto L%d_cmp_%d\n",scope,cmp_number);

		fprintf(file,"L%d_cmp_%d:\n\ticonst_1\n",scope,cmp_number-1);
		
		fprintf(file,"L%d_cmp_%d:\n",scope,cmp_number++);
		printf("%s\n",$2);
		//fprintf(file,"\t%s\n",instruction);
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
			HAS_ERROR=1;
			$$="float32";//conversion
		}
		$$=$1;
		printf("%s\n",$2);
		if(!strcmp($1,"int32"))
			fprintf(file,"\ti%s\n",lower_str($2));
		else
			fprintf(file,"\tf%s\n",lower_str($2));
	}
	|B4{$$=$1;}
;
B4
	:B4 Mul_op UnaryExpr{	


		if(!strcmp($1,"unknown")||!strcmp($3,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($2,"REM")&&(!(strcmp($1,"float32"))||!(strcmp($3,"float32")))){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: (operator REM not defined on float32)\n",yylineno);
		}
		else if(strcmp($1,$3)){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
			$$="float32";//conversion
		}
		$$=$1;
		printf("%s\n",$2);
		if(!strcmp($1,"int32"))
			fprintf(file,"\ti%s\n",lower_str($2));
		else
			fprintf(file,"\tf%s\n",lower_str($2));
	}
	|UnaryExpr{$$=find_type($1,&foo,&foo_b);}
;
UnaryExpr 
    : PrimaryExpr{$$=$1;} 
    | Unary_op UnaryExpr{
		$$=$2;
		if(!strcmp($1,"NOT"))
			fprintf(file,"\ticonst_1\n\tixor\n");//for xor operation
		else if(!strcmp($1,"NEG"))
			fprintf(file,"\t%cneg\n",$2[0]);
		printf("%s\n",$1);
	}
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
    | DIV{$$="DIV";}
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
    | IndexExpr{$$=$1;fprintf(file,"\t%caload\n",$1[0]);}
    | ConversionExpr{$$=$1;}
;

Operand
    : Literal{$$=$1;}
    | IDENT{
		int address=lookup_symbol($1,tail);
		bool is_array=0;
		$$=find_type($1,&foo,&is_array);
		if($$[0]=='s'||is_array)	
			fprintf(file,"\taload %d\n",address);
		else if($$[0]=='b')
			fprintf(file,"\tiload %d\n",address);
		else
			fprintf(file,"\t%cload %d\n",$$[0],address);
		
	}
	| LPAREN  Expression RPAREN{$$=$2;}
;

Literal
    : INT_LIT{fprintf(file,"\tldc %d\n",$1);printf("INT_LIT %d\n",$1);$$="int32";}
    | FLOAT_LIT{fprintf(file,"\tldc %f\n",$1);printf("FLOAT_LIT %f\n",$1);$$="float32";}
    | BOOL_LIT{fprintf(file,"\tldc %d\n",$1);printf("BOOL_LIT %d\n",$1);$$="bool";}
    | STRING_LIT{fprintf(file,"\tldc \"%s\"\n",$1);printf("STRING_LIT %s\n",$1);$$="string";} 
	| TRUE{fprintf(file,"\ticonst_1\n");printf("TRUE\n");$$="bool";}
	| FALSE{fprintf(file,"\ticonst_0\n");printf("FALSE\n");$$="bool";}
;

/*Index expression*/
IndexExpr
    : PrimaryExpr LBRACK Expression RBRACK{
		$$=$1;
	}//need to be checked
;

/*Coversion (type casting)*/
ConversionExpr
     : Type LPAREN Expression RPAREN{
		$$=$1;
		if(!strcmp($1,$3)){
			printf("error:%d: covert the same type",yylineno);
			HAS_ERROR=1;
		}
		else if(!strcmp($1,"float32")&&!strcmp($3,"int32")){
			fprintf(file,"\ti2f\n");
		}
		else if(!strcmp($1,"int32")&&!strcmp($3,"float32")){
			fprintf(file,"\tf2i\n");
		}
		else{
			printf("error:%d: cannot convert type %s to type %s",yylineno,$3,$1);
			HAS_ERROR=1;
		}
		printf("%c to %c\n",toupper($3[0]),toupper($1[0]));
	}
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
    : AssignmentStmt
    | Expression
    | IncDecStmt
;

/*Declarations statements*/
DeclarationStmt 
    : VAR IDENT Type DeclarationAssign{
		strcpy(_var,$2);
		int address;
		if($3[0]=='a'){
			address=create_symbol(_var,"array",_type+1);
			fprintf(file,"\tastore %d\n",address);				
		}
		else{
			if(!$4){
				if($3[0]=='i'||$3[0]=='b')
					fprintf(file,"\tldc 0\n");
				else if($3[0]=='f')
					fprintf(file,"\tldc 0.0\n");
				else//string
					fprintf(file,"\tldc \"\"\n");
			}
			strcpy(_type,$3);
			address=create_symbol(_var,_type,"-");				
			if($3[0]=='s')
				fprintf(file,"\tastore %d\n",address);
			else if($3[0]=='b')
				fprintf(file,"\tistore %d\n",address);
			else
				fprintf(file,"\t%cstore %d\n",$3[0],address);
		}
	}
;

DeclarationAssign
    : ASSIGN Expression{$$=1;}
    |{$$=0;}

/*Assignments statements*/
AssignmentStmt 
    : ExpressionVar Assign_op  Expression{	
		if(strlen($2)==10){//except ASSIGN
			if($1[0]=='s'||l_array)	
				fprintf(file,"\taload %d\n",l_address);
			else if($1[0]=='i'||$1[0]=='b')
				fprintf(file,"\tiload %d\n",l_address);
			else if($1[0]=='f')
				fprintf(file,"\tfload %d\n",l_address);
			fprintf(file,"\tswap\n");
			char* temp_op = lower_substr($2,3);
			fprintf(file,"\t%c%s\n",$1[0],temp_op);
			free(temp_op);
		}
		if(l_array){
			fprintf(file,"\t%castore\n",$1[0]);
			l_array=0;//reset to default	
		}
		else if($1[0]=='s')
			fprintf(file,"\tastore %d\n",l_address);
		else if($1[0]=='b')
			fprintf(file,"\tistore %d\n",l_address);
		else{
			fprintf(file,"\t%cstore %d\n",$1[0],l_address);
		}

		if(!strcmp($1,"unknown")||!strcmp($1,"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp($2,"REM_ASSIGN")&&(!strcmp($1,"float32")||!strcmp($3,"float32"))){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: (operator REM_ASSIGN not defined on float32)\n",yylineno);
		}
		else if(strcmp($1,$3)){
			HAS_ERROR=1;
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,$2,$1,$3);
		}
		else if(left_value_error){
			printf("error:%d: cannot assign to %s\n",yylineno,$1);
			HAS_ERROR=1;
			left_value_error=0;
		}
		printf("%s\n",$2);
	}
;

ExpressionVar
	:IndexExpr{$$=$1;l_array=1;}
	|Literal{$$=$1;left_value_error=1;}
	|IDENT{
		bool is_array=0;
		$$=find_type($1,&foo,&is_array);
		l_address=lookup_symbol($1,tail);
	}
;

Assign_op
    : ASSIGN {$$="ASSIGN";}
    | ADD_ASSIGN {$$="ADD_ASSIGN";}
    | SUB_ASSIGN {$$="SUB_ASSIGN";}
    | MUL_ASSIGN {$$="MUL_ASSIGN";}
    | DIV_ASSIGN {$$="DIV_ASSIGN";}
    | REM_ASSIGN {$$="REM_ASSIGN";}
;

/*IncDec statements*/
IncDecStmt
    : ExpressionVar{
	if($1[0]=='s'||l_array)	
		fprintf(file,"\taload %d\n",l_address);
	else if($1[0]=='i')
		fprintf(file,"\tiload %d\n\tldc 1\n",l_address);
	else if($1[0]=='f')
		fprintf(file,"\tfload %d\n\tldc 1.0\n",l_address);
	else
		fprintf(file,"\terror for IncDec\n");
	} IncDec{
		fprintf(file,"\t%c%s\n",$1[0],$3);
		if(l_array){
			fprintf(file,"\t%castore\n",$1[0]);
			l_array=0;//reset to default	
		}
		else{
			fprintf(file,"\t%cstore %d\n",$1[0],l_address);
		}
	}
;

IncDec
    : INC{printf("INC\n");$$="add";}
    | DEC{printf("DEC\n");$$="sub";}
;

/*Block*/
Block
    : LBRACE{++scope;} StatementList{dump_symbol(tail);} RBRACE{--scope;}
;


/*If statements* {stack(&stack_top,"#");}*/
IfStmt
	:IfBlock{fprintf(file,"\nL%d_if_exit_%d:\n",scope,if_exit_num[scope]++);}
	| IfBlock ELSE IfStmt
	| IfBlock ELSE Block{
		fprintf(file,"\nL%d_if_exit_%d:\n",scope,if_exit_num[scope]++);
	}
;

IfCondition
	:IF Condition{
		fprintf(file,"\tifeq L%d_if_%d\n",scope,if_num[scope]);//if false, jump
	}

IfBlock
    : IfCondition Block{	
		fprintf(file,"\tgoto L%d_if_exit_%d\n",scope,if_exit_num[scope]);//after if block
		fprintf(file,"\nL%d_if_%d:\n",scope,if_num[scope]++);		
	}
Condition
    : Expression{
		if(strcmp($1,"bool")){
			HAS_ERROR=1;
			printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,$1);
		}
	}
;


/*For statements*/
ForStmt
    : FOR{fprintf(file,"L%d_for_begin%d:\n",scope,for_num[scope]);} ForCondition Block{
	fprintf(file,"\tgoto L%d_for_begin%d\n",scope,for_num[scope]);
	fprintf(file,"L%d_for_exiti%d:\n",scope,for_num[scope]++);	
}
;

ForCondition
    : Condition{fprintf(file,"\tifeq L%d_for_exit%d\n",scope,for_num[scope]);}
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
	: PrintType LPAREN Expression RPAREN{
		char print_type;
		if(!strcmp($3,"bool")){
			print_type='Z';
			fprintf(file,"\tifne L%d_cmp_%d\n",scope,cmp_number++);
			fprintf(file,"\tldc \"false\"\n\tgoto L%d_cmp_%d\n",scope,cmp_number);
			fprintf(file,"L%d_cmp_%d:\n\tldc \"true\"\n",scope,cmp_number-1);
			fprintf(file,"L%d_cmp_%d:\n",scope,cmp_number++);
			
		}
		else
			print_type=toupper($3[0]);
		printf("%s %s\n",$1,$3);
		fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
		char* temp_type=lower_str($1);
		if(print_type=='Z'||print_type=='S')
			fprintf(file,"\tinvokevirtual java/io/PrintStream/%s(Ljava/lang/String;)V\n\n",temp_type);
		else 
			fprintf(file,"\tinvokevirtual java/io/PrintStream/%s(%c)V\n\n",temp_type,print_type);
		free(temp_type);
	}
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
char* lower_str(char* str){
	//printf("%d\n",strlen(str));
	char* u_s=malloc(strlen(str)*sizeof(char));	
	for(int i=0;i<strlen(str);++i){
		u_s[i]=tolower(str[i]);
	}
	return u_s;
}
char* lower_substr(char* str, int  len){
	//printf("%d\n",strlen(str));
	if(len>strlen(str)){
		printf("len of the substr is to small!\n");
		return str;
	}
	char* u_s=malloc(len*sizeof(char));	
	for(int i=0;i<len;++i){
		u_s[i]=tolower(str[i]);
	}
	return u_s;
}

char* find_type(char* id,int* line,bool* is_array){
	if(!strcmp(id,"int32")||!strcmp(id,"float32")||!strcmp(id,"string")||!strcmp(id,"bool"))
		return id;
	stb* temp= tail;
	bool found=0;
	while(temp!=NULL&&strcmp(temp->name,id)){
		while(temp->child!=NULL){
			temp=temp->child;
			if(!strcmp(temp->name,id)){
				found=1;
				break;
			}
		}
		if(found)
			break;
		else
			temp=temp->prev;//jump to outer block
	}
	if(temp==NULL){
		//printf("Error: find ID in empty stack!\n");
		return "unknown";
	}
	else{
		char* t;
		if(!strcmp(temp->type,"array")){
			*is_array=1;
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
	if_num = malloc(30*sizeof(int));
	if_exit_num = malloc(30*sizeof(int));
	for_num = malloc(30*sizeof(int));
	for(int i=0;i<30;++i){
		if_num[i]=0;
		if_exit_num[i]=0;
		for_num[i]=0;
	}
	file=fopen("hw3.j","w");
	fprintf(file,".source hw3.j\n");
	fprintf(file,".class public Main\n");
	fprintf(file,".super java/lang/Object\n");
	fprintf(file,".method public static main([Ljava/lang/String;)V\n");
	fprintf(file,".limit stack 100\n");
	fprintf(file,".limit locals 100\n");
    yylineno = 0;
    yyparse();
	dump_symbol(tail);
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
	
	if(HAS_ERROR){
		remove("hw3.j");
	}
	else{	
		fprintf(file,"	return\n");
		fprintf(file,".end method\n");
	}
	free(if_num);
	free(if_exit_num);
	free(for_num);
    return 0;
}

static int create_symbol(char* id, char* type, char* etype){

	if(tail==NULL||tail->scope!=scope){//empty symbol table or new scope
		stb* n=new_stb_node(0,id,type,etype,tail,NULL,NULL);
		n->last_child=n;
		tail=n;
		insert_symbol(n);
		return n->address; 
	}
	else{
		int* pre_line=malloc(sizeof(int));
		if(strcmp(find_type(id,pre_line,&foo_b),"unknown")){
			printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,id,*pre_line);
			return -1;	
		}
		stb* n=new_stb_node(tail->last_child->index+1,id,type,etype,NULL,NULL,NULL);
		tail->last_child->child=n;
		tail->last_child=n;
		insert_symbol(n);
		return n->address;	
	}
	
}

static void insert_symbol(stb* n) {
	
    printf("> Insert {%s} into symbol table (scope level: %d)\n", n->name, scope);
}

static int lookup_symbol(char* id, stb* n) {
	while(n!=NULL){
		if(!strcmp(n->name,id))
			return n->address;
		while(n->child!=NULL){
			n=n->child;
			if(!strcmp(n->name,id)){
				printf("IDENT (name=%s, address=%d)\n",n->name,n->address);
				return n->address;
			}
		}
		n=n->prev;//jump to outer block
	}
	
	printf("error:%d: undefined: %s\n",yylineno+1,id);
	return -100;
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
