/*Definition section */
%{
    #include <stdio.h>	
    #include <stdbool.h>
    #include <string.h>
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
	
	static int scope=0;	
    static int address=0;
    typedef struct symbol_table stb;

    struct symbol_table{
		int index;
		char* name;
		char* type;
		int address;
		int lineno;
		char* element_type;	
		stb* next;
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
    static void lookup_symbol();
    static void dump_symbol();
	
	stb* new_stb_node(int index,char* name, char* type,
						char* element_type,stb* next,stb* prev,stb*child,stb* last_child);
	
	/*initialize the head of symbol table*/
	stb* head = NULL;
	stb* tail = NULL;
	
	char _type [7];
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
%token ADD SUB MUL QUO MOD INC DEC REM//arithmetric
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
//%type <i_val> INT_LIT
//%type <f_val> FLOAT_LIT
//%type <s_val> STRING_LIT
//%type <b_val> BOOL_LIT
%type <string> Type TypeName ArrayType
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
    : TypeName 
    | ArrayType
;

TypeName 
    : INT {$$=$1;}
    | FLOAT {$$=$1;}
    | STRING {$$=$1;}
    | BOOL {$$=$1;}
;

ArrayType 
    :  LBRACK  Expression RBRACK Type
;

/*Expressions*/
Expression 
    : UnaryExpr 
    | Expression Binary_op Expression
;

UnaryExpr 
    : PrimaryExpr 
    | Unary_op UnaryExpr
;

Binary_op
    : LOR 
    | LAND 
    | Cmp_op 
    | Add_op 
    | Mul_op
;

Cmp_op 
    : EQL 
    | NEQ 
    | LSS 
    | LEQ 
    | GTR 
    | GEQ
;

Add_op 
    : ADD 
    | SUB
;

Mul_op 
    : MUL 
    | QUO 
    | REM
;

Unary_op 
    : ADD 
    | SUB 
    | NOT
;

/*Primary expression*/
PrimaryExpr
    : Operand
    | IndexExpr
    | ConversionExpr
;

Operand
    : Literal
    | IDENT
    | LPAREN Expression RPAREN
;

Literal
    : INT_LIT
    | FLOAT_LIT
    | BOOL_LIT
    | STRING_LIT 
;

/*Index expression*/
IndexExpr
    : PrimaryExpr LBRACK Expression RBRACK
;

/*Coversion (type casting)*/
ConversionExpr
     : Type LPAREN Expression RPAREN
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
		strcpy(_type,$3);
		create_symbol(_var,_type,"-");				
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
    : ASSIGN 
    | ADD_ASSIGN 
    | SUB_ASSIGN 
    | MUL_ASSIGN
    | QUO_ASSIGN
    | REM_ASSIGN
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
    : LBRACE StatementList RBRACE{++scope;}
;

StatementList
    :  StatementList Statement 
    |/*empty*/  
;

/*If statements*/
IfStmt
    : IF Condition Block ElseIfStmt
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
    : PrintType LPAREN Expression RPAREN
;

PrintType
    : PRINT
    | PRINTLN
;
%%
/* C code section */

stb* new_stb_node(int index,char* name, char* type,
						char* element_type,stb* next,stb* prev,stb*child,stb* last_child){
	stb* node = malloc(sizeof(stb));
	node->index=index;
	node->name=name;
	node->type=type;
	node->address=++address;
	node->element_type=element_type;
	node->lineno=yylineno;
	node->next=next;
	node->prev=prev;
	node->child=child;
	node->last_child=last_child;
	return node;
}
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
	
	head = new_stb_node(0,"","","",NULL,NULL,NULL,head);
	tail = head;
    yylineno = 0;
    yyparse();
	dump_symbol(tail);
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(char* id, char* type, char* etype){

	if(tail==NULL){printf("Error stb tail\n");}
	//else if(tail->last_child==NULL){printf("Error stb!\n");}
	else if(tail==head){//empty stb
		stb* n=new_stb_node(0,id,type,etype,NULL,head,NULL,NULL);
		n->last_child=n;
		tail=n;
		insert_symbol(n);
	}
	else{
		stb* n=new_stb_node(tail->last_child->index+1,id,type,etype,NULL,NULL,NULL,NULL);
		tail->last_child->child=n;
		tail->last_child=n;
		insert_symbol(n);	
	}
}

static void insert_symbol(stb* n) {
	
    printf("> Insert {%s} into symbol table (scope level: %d)\n", n->name, scope);
}

static void lookup_symbol() {
}

static void dump_symbol(stb* n) {
    printf("> Dump symbol table (scope level: %d)\n", 0);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
	stb* pretail=tail->prev;
	stb* temp;
	while(tail!=NULL){
		
    	printf("%-10d%-10s%-10s%-10d%-10d%s\n",
			tail->index,tail->name,tail->type,tail->address,tail->lineno,tail->element_type);
		temp=tail;
		tail=tail->child;
		free(temp);
	}
    tail=pretail;
}
