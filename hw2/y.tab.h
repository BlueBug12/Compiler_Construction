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
    NEWLINE = 265,
    ADD = 266,
    SUB = 267,
    MUL = 268,
    QUO = 269,
    REM = 270,
    INC = 271,
    DEC = 272,
    LSS = 273,
    GTR = 274,
    LEQ = 275,
    GEQ = 276,
    EQL = 277,
    NEQ = 278,
    ASSIGN = 279,
    ADD_ASSIGN = 280,
    SUB_ASSIGN = 281,
    MUL_ASSIGN = 282,
    QUO_ASSIGN = 283,
    REM_ASSIGN = 284,
    LAND = 285,
    LOR = 286,
    NOT = 287,
    TRUE = 288,
    FALSE = 289,
    IF = 290,
    ELSE = 291,
    FOR = 292,
    VAR = 293,
    PRINT = 294,
    PRINTLN = 295,
    IDENT = 296,
    INT = 297,
    FLOAT = 298,
    BOOL = 299,
    STRING = 300,
    INT_LIT = 301,
    FLOAT_LIT = 302,
    STRING_LIT = 303,
    BOOL_LIT = 304
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
#define NEWLINE 265
#define ADD 266
#define SUB 267
#define MUL 268
#define QUO 269
#define REM 270
#define INC 271
#define DEC 272
#define LSS 273
#define GTR 274
#define LEQ 275
#define GEQ 276
#define EQL 277
#define NEQ 278
#define ASSIGN 279
#define ADD_ASSIGN 280
#define SUB_ASSIGN 281
#define MUL_ASSIGN 282
#define QUO_ASSIGN 283
#define REM_ASSIGN 284
#define LAND 285
#define LOR 286
#define NOT 287
#define TRUE 288
#define FALSE 289
#define IF 290
#define ELSE 291
#define FOR 292
#define VAR 293
#define PRINT 294
#define PRINTLN 295
#define IDENT 296
#define INT 297
#define FLOAT 298
#define BOOL 299
#define STRING 300
#define INT_LIT 301
#define FLOAT_LIT 302
#define STRING_LIT 303
#define BOOL_LIT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "compiler_hw2.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
