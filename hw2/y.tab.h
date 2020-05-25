/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LPAREN = 258,
    RPAREN = 259,
    LBRACK = 260,
    RBRACK = 261,
    LBRACE = 262,
    RBRACE = 263,
    SEMICOLON = 264,
    COMMA = 265,
    QUOTA = 266,
    NEWLINE = 267,
    ADD = 268,
    SUB = 269,
    MUL = 270,
    QUO = 271,
    MOD = 272,
    INC = 273,
    DEC = 274,
    REM = 275,
    LSS = 276,
    GTR = 277,
    LEQ = 278,
    GEQ = 279,
    EQL = 280,
    NEQ = 281,
    ASSIGN = 282,
    ADD_ASSIGN = 283,
    SUB_ASSIGN = 284,
    MUL_ASSIGN = 285,
    QUO_ASSIGN = 286,
    REM_ASSIGN = 287,
    LAND = 288,
    LOR = 289,
    NOT = 290,
    TRUE = 291,
    FALSE = 292,
    IF = 293,
    ELSE = 294,
    FOR = 295,
    VAR = 296,
    PRINT = 297,
    PRINTLN = 298,
    IDENT = 299,
    INT = 300,
    FLOAT = 301,
    BOOL = 302,
    STRING = 303,
    INT_LIT = 304,
    FLOAT_LIT = 305,
    STRING_LIT = 306,
    BOOL_LIT = 307
  };
#endif
/* Tokens.  */
#define LPAREN 258
#define RPAREN 259
#define LBRACK 260
#define RBRACK 261
#define LBRACE 262
#define RBRACE 263
#define SEMICOLON 264
#define COMMA 265
#define QUOTA 266
#define NEWLINE 267
#define ADD 268
#define SUB 269
#define MUL 270
#define QUO 271
#define MOD 272
#define INC 273
#define DEC 274
#define REM 275
#define LSS 276
#define GTR 277
#define LEQ 278
#define GEQ 279
#define EQL 280
#define NEQ 281
#define ASSIGN 282
#define ADD_ASSIGN 283
#define SUB_ASSIGN 284
#define MUL_ASSIGN 285
#define QUO_ASSIGN 286
#define REM_ASSIGN 287
#define LAND 288
#define LOR 289
#define NOT 290
#define TRUE 291
#define FALSE 292
#define IF 293
#define ELSE 294
#define FOR 295
#define VAR 296
#define PRINT 297
#define PRINTLN 298
#define IDENT 299
#define INT 300
#define FLOAT 301
#define BOOL 302
#define STRING 303
#define INT_LIT 304
#define FLOAT_LIT 305
#define STRING_LIT 306
#define BOOL_LIT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "compiler_hw2.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
