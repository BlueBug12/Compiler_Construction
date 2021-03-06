/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    int line_num = 0;
    int comment_num = 0;
    int  new_line=-1;  /*-1  for initial state; 0 for new line; 1 for comment */
    char* sub_string(char* str){
	/*seperate quotas*/
	{ printf("%-8s \t %s\n", "\"", "QUOTA"); }
	char* sub = calloc(strlen(str)-2,sizeof(char));
	strncpy(sub,str+1,strlen(str)-2);
	{ printf("%-8s \t %s\n", sub, "STRING"); }
	{ printf("%-8s \t %s\n", "\"", "QUOTA"); }
	return sub;
    }
    void c_comment_(char* str){
	if(new_line!=1){++comment_num;}
	new_line=1;
	int size = strlen(str);
	int counter=0;
	for(int i=0;i<size;++i){
		if(str[i]=='\n'){
			++line_num;
			++comment_num;
			++counter;
			if(counter){	
				printf("\n%-8s\t %s\n","","C Comment");	
			}
		
		}
		else{
			printf("%c",str[i]);
		}	
	}
	printf("%-7s\t %s\n","","C Comment");
    }
%}

/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber ({digit}*\.{digit}+)
c_comment \/\*([^*]|(\*[^/]))*\*\/
cpp_comment \/\/.*
string  \"[\x00-\x21|\x23-\x7f]*\"
/* Rules section */
%%
"print"     { printf("%-8s \t %s\n", yytext, "PRINT"); }
"println"   { printf("%-8s \t %s\n", yytext, "PRINTLN"); }
"if"        { printf("%-8s \t %s\n", yytext, "IF"); }
"else"      { printf("%-8s \t %s\n", yytext, "ELSE"); }
"for"       { printf("%-8s \t %s\n", yytext, "FOR"); }
"int32"     { printf("%-8s \t %s\n", yytext, "INT"); }
"float32"   { printf("%-8s \t %s\n", yytext, "FLOAT"); }
"string"    { printf("%-8s \t %s\n", yytext, "STRING"); }
"bool"      { printf("%-8s \t %s\n", yytext, "BOOL"); }
"true"      { printf("%-8s \t %s\n", yytext, "TRUE"); }
"false"     { printf("%-8s \t %s\n", yytext, "FALSE"); }
"var"       { printf("%-8s \t %s\n", yytext, "VAR"); }
{inumber}   { printf("%-8s \t %s\n", yytext, "INT_LIT"); }
{fnumber}   { printf("%-8s \t %s\n", yytext, "FLOAT_LIT"); }
{string}    { sub_string(yytext);}
{id}        { printf("%-8s \t %s\n", yytext, "IDENT"); }
{c_comment}   {c_comment_(yytext); }
{cpp_comment} { printf("%-8s \t %s\n",yytext , "C++ Comment");if(new_line!=1)++comment_num; }
"+"         { printf("%-8s \t %s\n", yytext, "ADD"); }
"-"         { printf("%-8s \t %s\n", yytext, "SUB"); }
"*"         { printf("%-8s \t %s\n", yytext, "MUL"); }
"/"         { printf("%-8s \t %s\n", yytext, "QUO"); }
"%"         { printf("%-8s \t %s\n", yytext, "REM"); }
"++"        { printf("%-8s \t %s\n", yytext, "INC"); }
"--"        { printf("%-8s \t %s\n", yytext, "DEC"); }
">"         { printf("%-8s \t %s\n", yytext, "GTR"); }
"<"         { printf("%-8s \t %s\n", yytext, "LSS"); }
">="        { printf("%-8s \t %s\n", yytext, "GEQ"); }
"<="        { printf("%-8s \t %s\n", yytext, "LEQ"); }
"=="        { printf("%-8s \t %s\n", yytext, "EQL"); }
"!="        { printf("%-8s \t %s\n", yytext, "NEQ"); }
"="         { printf("%-8s \t %s\n", yytext, "ASSIGN"); }
"+="        { printf("%-8s \t %s\n", yytext, "ADD_ASSIGN"); }
"-="        { printf("%-8s \t %s\n", yytext, "SUB_ASSIGN"); }
"*="        { printf("%-8s \t %s\n", yytext, "MUL_ASSIGN"); }
"/="        { printf("%-8s \t %s\n", yytext, "QUO_ASSIGN"); }
"%="        { printf("%-8s \t %s\n", yytext, "REM_ASSIGN"); }
"&&"        { printf("%-8s \t %s\n", yytext, "LAND"); }
"||"        { printf("%-8s \t %s\n", yytext, "LOR"); }
"!"         { printf("%-8s \t %s\n", yytext, "NOT"); }
"("         { printf("%-8s \t %s\n", yytext, "LPAREN"); }
")"         { printf("%-8s \t %s\n", yytext, "RPAREN"); }
"["         { printf("%-8s \t %s\n", yytext, "LBRACK"); }
"]"         { printf("%-8s \t %s\n", yytext, "RBRACK"); }
"{"         { printf("%-8s \t %s\n", yytext, "LBRACE"); }
"}"         { printf("%-8s \t %s\n", yytext, "RBRACE"); }
";"         { printf("%-8s \t %s\n", yytext, "SEMICOLON"); }
","         { printf("%-8s \t %s\n", yytext, "COMMA"); }
"\""        { printf("%-8s \t %s\n", yytext, "QUOTA"); }
"\n"        { printf("%-8s \t %s\n", "", "NEWLINE");++line_num;new_line=0; }
<<EOF>>     { line_num++; yyterminate(); }
.           {;}

%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}

