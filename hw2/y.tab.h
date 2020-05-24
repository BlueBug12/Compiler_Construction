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
    POS = 276,
    NEG = 277,
    LSS = 278,
    GTR = 279,
    LEQ = 280,
    GEQ = 281,
    EQL = 282,
    NEQ = 283,
    ASSIGN = 284,
    ADD_ASSIGN = 285,
    SUB_ASSIGN = 286,
    MUL_ASSIGN = 287,
    QUO_ASSIGN = 288,
    REM_ASSIGN = 289,
    LAND = 290,
    LOR = 291,
    NOT = 292,
    TRUE = 293,
    FALSE = 294,
    IF = 295,
    ELSE = 296,
    FOR = 297,
    VAR = 298,
    PRINT = 299,
    PRINTLN = 300,
    IDENT = 301,
    INT = 302,
    FLOAT = 303,
    BOOL = 304,
    STRING = 305,
    INT_LIT = 306,
    FLOAT_LIT = 307,
    STRING_LIT = 308,
    BOOL_LIT = 309
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
#define POS 276
#define NEG 277
#define LSS 278
#define GTR 279
#define LEQ 280
#define GEQ 281
#define EQL 282
#define NEQ 283
#define ASSIGN 284
#define ADD_ASSIGN 285
#define SUB_ASSIGN 286
#define MUL_ASSIGN 287
#define QUO_ASSIGN 288
#define REM_ASSIGN 289
#define LAND 290
#define LOR 291
#define NOT 292
#define TRUE 293
#define FALSE 294
#define IF 295
#define ELSE 296
#define FOR 297
#define VAR 298
#define PRINT 299
#define PRINTLN 300
#define IDENT 301
#define INT 302
#define FLOAT 303
#define BOOL 304
#define STRING 305
#define INT_LIT 306
#define FLOAT_LIT 307
#define STRING_LIT 308
#define BOOL_LIT 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "compiler_hw2.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
