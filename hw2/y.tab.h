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
    NEWLINE = 266,
    ADD = 267,
    SUB = 268,
    MUL = 269,
    QUO = 270,
    MOD = 271,
    INC = 272,
    DEC = 273,
    REM = 274,
    LSS = 275,
    GTR = 276,
    LEQ = 277,
    GEQ = 278,
    EQL = 279,
    NEQ = 280,
    ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    MUL_ASSIGN = 284,
    QUO_ASSIGN = 285,
    REM_ASSIGN = 286,
    LAND = 287,
    LOR = 288,
    NOT = 289,
    TRUE = 290,
    FALSE = 291,
    IF = 292,
    ELSE = 293,
    FOR = 294,
    VAR = 295,
    PRINT = 296,
    PRINTLN = 297,
    IDENT = 298,
    INT = 299,
    FLOAT = 300,
    BOOL = 301,
    STRING = 302,
    INT_LIT = 303,
    FLOAT_LIT = 304,
    STRING_LIT = 305,
    BOOL_LIT = 306
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
#define NEWLINE 266
#define ADD 267
#define SUB 268
#define MUL 269
#define QUO 270
#define MOD 271
#define INC 272
#define DEC 273
#define REM 274
#define LSS 275
#define GTR 276
#define LEQ 277
#define GEQ 278
#define EQL 279
#define NEQ 280
#define ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define MUL_ASSIGN 284
#define QUO_ASSIGN 285
#define REM_ASSIGN 286
#define LAND 287
#define LOR 288
#define NOT 289
#define TRUE 290
#define FALSE 291
#define IF 292
#define ELSE 293
#define FOR 294
#define VAR 295
#define PRINT 296
#define PRINTLN 297
#define IDENT 298
#define INT 299
#define FLOAT 300
#define BOOL 301
#define STRING 302
#define INT_LIT 303
#define FLOAT_LIT 304
#define STRING_LIT 305
#define BOOL_LIT 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "compiler_hw2.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
