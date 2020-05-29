/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw3.y"

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

#line 141 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    DIV = 269,
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
    DIV_ASSIGN = 283,
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
#define DIV 269
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
#define DIV_ASSIGN 283
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
#line 78 "compiler_hw3.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 298 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   130,   131,   136,   137,   148,   149,   150,
     151,   155,   159,   180,   183,   209,   212,   244,   247,   264,
     267,   289,   292,   293,   304,   307,   310,   311,   312,   313,
     314,   315,   319,   320,   324,   325,   326,   330,   331,   332,
     337,   338,   339,   343,   344,   356,   360,   361,   362,   363,
     364,   365,   370,   377,   399,   400,   401,   402,   403,   404,
     405,   409,   410,   411,   416,   445,   446,   450,   496,   497,
     498,   506,   507,   508,   509,   510,   511,   516,   516,   538,
     539,   544,   544,   544,   550,   551,   552,   558,   563,   568,
     579,   579,   587,   588,   592,   592,   596,   592,   603,   607,
     612,   636,   637
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "SEMICOLON", "NEWLINE", "ADD", "SUB", "MUL", "DIV",
  "REM", "INC", "DEC", "LSS", "GTR", "LEQ", "GEQ", "EQL", "NEQ", "ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "LAND", "LOR", "NOT", "TRUE", "FALSE", "IF", "ELSE", "FOR", "VAR",
  "PRINT", "PRINTLN", "IDENT", "INT", "FLOAT", "BOOL", "STRING", "INT_LIT",
  "FLOAT_LIT", "STRING_LIT", "BOOL_LIT", "$accept", "Program",
  "StatementList", "Type", "TypeName", "ArrayType", "Expression", "B1",
  "B2", "B3", "B4", "UnaryExpr", "LA", "LO", "Cmp_op", "Add_op", "Mul_op",
  "Unary_op", "PrimaryExpr", "Operand", "Literal", "IndexExpr",
  "ConversionExpr", "Statement", "SimpleStmt", "DeclarationStmt",
  "DeclarationAssign", "AssignmentStmt", "ExpressionVar", "Assign_op",
  "IncDecStmt", "$@1", "IncDec", "Block", "$@2", "$@3", "IfStmt",
  "IfCondition", "IfBlock", "Condition", "ForStmt", "$@4", "ForCondition",
  "ForClause", "$@5", "$@6", "$@7", "InitStmt", "PosStmt", "PrintStmt",
  "PrintType", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    67,    67,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
      67,   -58,   -11,   -58,   -58,   104,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,    34,     6,    64,   -58,   -58,    46,
      51,   160,    21,    14,   -58,    67,    32,   -58,   125,   148,
     -58,   -58,    77,    79,   -58,    -5,   -58,    80,    83,    88,
      62,    86,    92,   100,   -58,     4,   -58,   -58,    60,     6,
      46,   -58,   114,    31,   -58,   -58,    67,   -58,    67,   -58,
      67,   -58,   -58,   -58,   -58,   -58,   -58,    67,   -58,   -58,
      67,   -58,   -58,   -58,    67,   -58,    67,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    67,    68,   -58,   -58,   -58,
       7,   -58,   -58,    67,   -58,    31,     6,    73,   -58,   -58,
      88,   -58,   109,    98,    27,    51,   160,    21,    14,   -58,
      63,    46,   -58,   -58,   -58,   -58,   -58,    61,   -58,   115,
     -58,   -58,    67,   -58,   -58,   -58,   -58,   -58,    67,    46,
     -58,   118,   -58,   114,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    81,    60,    37,    38,    39,    50,    51,
       0,    90,     0,   101,   102,    44,     7,     8,    10,     9,
      46,    47,    49,    48,     0,     2,     0,     5,     6,    62,
      13,    15,    17,    19,    21,     0,    22,    40,    43,    41,
      42,     4,     0,     0,    61,    77,    63,     0,     0,     0,
      84,     0,     0,     0,    44,     0,    43,    41,     0,     0,
      89,    87,     0,     0,     1,     3,     0,    25,     0,    24,
       0,    28,    30,    29,    31,    26,    27,     0,    32,    33,
       0,    34,    35,    36,     0,    23,     0,    55,    54,    71,
      72,    73,    74,    75,    76,     0,     0,    56,    57,    88,
       0,    58,    59,     0,    45,     0,    82,    62,    98,    92,
       0,    93,     0,    66,     0,    12,    14,    16,    18,    20,
       0,    67,    79,    80,    78,    86,    85,     0,    11,     0,
      91,    94,     0,    64,    53,    52,   100,    83,     0,    65,
      95,     0,    96,     0,    99,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,    65,   -48,   -58,   -58,     2,    69,    66,    58,
      59,   -28,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     1,   -58,   -23,   -57,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -39,   -58,   -58,    38,   -58,   -58,   -56,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    70,    68,    77,    80,    84,    35,    36,    37,
      56,    57,    40,    41,    42,    43,   133,    44,    45,    95,
      46,    96,   124,    47,    59,   129,    48,    49,    50,    61,
      51,    62,   110,   111,   138,   141,   143,   112,   145,    52,
      53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    39,    65,    55,    58,   108,   109,    85,   104,     1,
      99,     2,    60,     3,     3,   113,     4,     5,     6,    89,
      90,    91,    92,    93,    94,    38,    39,    81,    82,    83,
      63,   134,    78,    79,    64,    67,     2,    86,     7,     8,
       9,    10,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   119,   128,    67,    38,
      39,   125,    38,    39,   107,   136,   105,    66,   114,   135,
       1,   130,     2,    16,    17,    18,    19,    67,     5,     6,
     -89,    69,   140,    65,   122,   123,   144,    87,   120,    88,
      97,    67,    67,    98,    67,     3,   101,   121,   100,     7,
       8,     9,   102,   103,    67,   127,    38,    39,    54,    16,
      17,    18,    19,    20,    21,    22,    23,     1,   131,     2,
     -70,   -70,   132,   137,   106,     5,     6,   142,   -70,   -70,
     -70,   -70,   -70,   -70,   139,   117,   116,   115,   126,   118,
      60,   -69,   -69,    38,    39,     0,     7,     8,     9,   -69,
     -69,   -69,   -69,   -69,   -69,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   -68,   -68,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,   -68,   -68,    71,    72,
      73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
       0,     0,    25,     1,     2,    62,    62,    35,     4,     3,
      49,     5,    10,     7,     7,    63,    10,    11,    12,    24,
      25,    26,    27,    28,    29,    25,    25,    13,    14,    15,
      41,     4,    11,    12,     0,    31,     5,     5,    32,    33,
      34,    35,    35,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    84,   105,    31,    59,
      59,   100,    62,    62,    62,     4,     6,     3,    66,     6,
       3,   110,     5,    42,    43,    44,    45,    31,    11,    12,
       7,    30,   138,   106,    16,    17,   143,    10,    86,    10,
      10,    31,    31,    10,    31,     7,    10,    95,    36,    32,
      33,    34,    10,     3,    31,   103,   106,   106,    41,    42,
      43,    44,    45,    46,    47,    48,    49,     3,     9,     5,
      16,    17,    24,     8,    59,    11,    12,     9,    24,    25,
      26,    27,    28,    29,   132,    77,    70,    68,   100,    80,
     138,    16,    17,   143,   143,    -1,    32,    33,    34,    24,
      25,    26,    27,    28,    29,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    18,    19,
      20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,    10,    11,    12,    32,    33,    34,
      35,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    77,    78,    80,    83,    86,    87,
      88,    90,    99,   100,    41,    56,    70,    71,    56,    84,
      56,    89,    91,    41,     0,    73,     3,    31,    63,    30,
      62,    18,    19,    20,    21,    22,    23,    64,    11,    12,
      65,    13,    14,    15,    66,    61,     5,    10,    10,    24,
      25,    26,    27,    28,    29,    79,    81,    10,    10,    83,
      36,    10,    10,     3,     4,     6,    52,    56,    74,    89,
      92,    93,    97,    53,    56,    57,    58,    59,    60,    61,
      56,    56,    16,    17,    82,    83,    86,    56,    53,    85,
      83,     9,    24,    76,     4,     6,     4,     8,    94,    56,
      89,    95,     9,    96,    74,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    76,    76,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    81,    80,    82,
      82,    84,    85,    83,    86,    86,    86,    87,    88,    89,
      91,    90,    92,    92,    94,    95,    96,    93,    97,    98,
      99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     4,     2,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       1,     0,     0,     5,     1,     3,     3,     2,     2,     1,
       0,     4,     1,     1,     0,     0,     0,     8,     1,     1,
       4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5:
#line 136 "compiler_hw3.y"
              {(yyval.string)=(yyvsp[0].string);}
#line 1601 "y.tab.c"
    break;

  case 6:
#line 137 "compiler_hw3.y"
               {
		_type[0]='a';
		strncpy(_type+1,(yyvsp[0].string),strlen((yyvsp[0].string)));
		char* temp = lower_substr((yyvsp[0].string),strlen((yyvsp[0].string))-2);
		fprintf(file,"\tnewarray %s\n",temp);
		free(temp);
		(yyval.string)=_type;
	}
#line 1614 "y.tab.c"
    break;

  case 7:
#line 148 "compiler_hw3.y"
          {(yyval.string)=(yyvsp[0].string);}
#line 1620 "y.tab.c"
    break;

  case 8:
#line 149 "compiler_hw3.y"
            {(yyval.string)=(yyvsp[0].string);}
#line 1626 "y.tab.c"
    break;

  case 9:
#line 150 "compiler_hw3.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1632 "y.tab.c"
    break;

  case 10:
#line 151 "compiler_hw3.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1638 "y.tab.c"
    break;

  case 11:
#line 155 "compiler_hw3.y"
                                     {(yyval.string)=(yyvsp[0].string);}
#line 1644 "y.tab.c"
    break;

  case 12:
#line 159 "compiler_hw3.y"
                      {


		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[-2].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32")){	
			printf("error:%d: invalid operation: (operator LOR not defined on float32)\n",yylineno);
			HAS_ERROR=1;
		}
		else if(!strcmp((yyvsp[-2].string),"int32")||!strcmp((yyvsp[0].string),"int32")){		
			printf("error:%d: invalid operation: (operator LOR not defined on int32)\n",yylineno);
			HAS_ERROR=1;
		}
		
		(yyval.string)="bool";	
		printf("%s\n",(yyvsp[-1].string));
		char* temp=lower_str((yyvsp[-1].string)+1);
		fprintf(file,"\ti%s\n",temp);
		free(temp);
	}
#line 1670 "y.tab.c"
    break;

  case 13:
#line 180 "compiler_hw3.y"
            {(yyval.string)=(yyvsp[0].string);}
#line 1676 "y.tab.c"
    break;

  case 14:
#line 183 "compiler_hw3.y"
                 {


		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32")){	
			printf("error:%d: invalid operation: (operator LAND not defined on float32)\n",yylineno);
			HAS_ERROR=1;
		}
		else if(!strcmp((yyvsp[-2].string),"int32")||!strcmp((yyvsp[0].string),"int32")){		
			printf("error:%d: invalid operation: (operator LAND not defined on int32)\n",yylineno);
			HAS_ERROR=1;
		}
		
		
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			HAS_ERROR=1;
		}
		(yyval.string)="bool";
		printf("%s\n",(yyvsp[-1].string));
		char* temp=lower_str((yyvsp[-1].string)+1);
		fprintf(file,"\ti%s\n",temp);
		free(temp);
	}
#line 1707 "y.tab.c"
    break;

  case 15:
#line 209 "compiler_hw3.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1713 "y.tab.c"
    break;

  case 16:
#line 212 "compiler_hw3.y"
                     {

		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			HAS_ERROR=1;
		}
		(yyval.string)="bool";
		if((yyvsp[-2].string)[0]=='i'){//int type
			fprintf(file,"\tisub\n");
		}
		else{//float type
			fprintf(file,"\tfcmpl\n");
		}
		if(!strcmp((yyvsp[-1].string),"LSS"))
			fprintf(file,"\tiflt ");
		else{				
			char* temp = lower_substr((yyvsp[-1].string),2);
			fprintf(file,"\tif%s ",temp);
			free(temp);		
		}
		fprintf(file,"L%d_cmp_%d\n\ticonst_0\n",scope,cmp_number++);
		fprintf(file,"\tgoto L%d_cmp_%d\n",scope,cmp_number);

		fprintf(file,"L%d_cmp_%d:\n\ticonst_1\n",scope,cmp_number-1);
		
		fprintf(file,"L%d_cmp_%d:\n",scope,cmp_number++);
		printf("%s\n",(yyvsp[-1].string));
		//fprintf(file,"\t%s\n",instruction);
	}
#line 1750 "y.tab.c"
    break;

  case 17:
#line 244 "compiler_hw3.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1756 "y.tab.c"
    break;

  case 18:
#line 247 "compiler_hw3.y"
                     {

		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			HAS_ERROR=1;
			(yyval.string)="float32";//conversion
		}
		(yyval.string)=(yyvsp[-2].string);
		printf("%s\n",(yyvsp[-1].string));
		if(!strcmp((yyvsp[-2].string),"int32"))
			fprintf(file,"\ti%s\n",lower_str((yyvsp[-1].string)));
		else
			fprintf(file,"\tf%s\n",lower_str((yyvsp[-1].string)));
	}
#line 1778 "y.tab.c"
    break;

  case 19:
#line 264 "compiler_hw3.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1784 "y.tab.c"
    break;

  case 20:
#line 267 "compiler_hw3.y"
                            {	


		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-1].string),"REM")&&(!(strcmp((yyvsp[-2].string),"float32"))||!(strcmp((yyvsp[0].string),"float32")))){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: (operator REM not defined on float32)\n",yylineno);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			(yyval.string)="float32";//conversion
		}
		(yyval.string)=(yyvsp[-2].string);
		printf("%s\n",(yyvsp[-1].string));
		if(!strcmp((yyvsp[-2].string),"int32"))
			fprintf(file,"\ti%s\n",lower_str((yyvsp[-1].string)));
		else
			fprintf(file,"\tf%s\n",lower_str((yyvsp[-1].string)));
	}
#line 1811 "y.tab.c"
    break;

  case 21:
#line 289 "compiler_hw3.y"
                  {(yyval.string)=find_type((yyvsp[0].string),&foo,&foo_b);}
#line 1817 "y.tab.c"
    break;

  case 22:
#line 292 "compiler_hw3.y"
                 {(yyval.string)=(yyvsp[0].string);}
#line 1823 "y.tab.c"
    break;

  case 23:
#line 293 "compiler_hw3.y"
                        {
		(yyval.string)=(yyvsp[0].string);
		if(!strcmp((yyvsp[-1].string),"NOT"))
			fprintf(file,"\ticonst_1\n\tixor\n");//for xor operation
		else if(!strcmp((yyvsp[-1].string),"NEG"))
			fprintf(file,"\t%cneg\n",(yyvsp[0].string)[0]);
		printf("%s\n",(yyvsp[-1].string));
	}
#line 1836 "y.tab.c"
    break;

  case 24:
#line 304 "compiler_hw3.y"
             {(yyval.string)="LAND";}
#line 1842 "y.tab.c"
    break;

  case 25:
#line 307 "compiler_hw3.y"
            {(yyval.string)="LOR";}
#line 1848 "y.tab.c"
    break;

  case 26:
#line 310 "compiler_hw3.y"
         {(yyval.string)="EQL";}
#line 1854 "y.tab.c"
    break;

  case 27:
#line 311 "compiler_hw3.y"
         {(yyval.string)="NEQ";}
#line 1860 "y.tab.c"
    break;

  case 28:
#line 312 "compiler_hw3.y"
             {(yyval.string)="LSS";}
#line 1866 "y.tab.c"
    break;

  case 29:
#line 313 "compiler_hw3.y"
         {(yyval.string)="LEQ";}
#line 1872 "y.tab.c"
    break;

  case 30:
#line 314 "compiler_hw3.y"
         {(yyval.string)="GTR";}
#line 1878 "y.tab.c"
    break;

  case 31:
#line 315 "compiler_hw3.y"
         {(yyval.string)="GEQ";}
#line 1884 "y.tab.c"
    break;

  case 32:
#line 319 "compiler_hw3.y"
         {(yyval.string)="ADD";}
#line 1890 "y.tab.c"
    break;

  case 33:
#line 320 "compiler_hw3.y"
             {(yyval.string)="SUB";}
#line 1896 "y.tab.c"
    break;

  case 34:
#line 324 "compiler_hw3.y"
         {(yyval.string)="MUL";}
#line 1902 "y.tab.c"
    break;

  case 35:
#line 325 "compiler_hw3.y"
         {(yyval.string)="DIV";}
#line 1908 "y.tab.c"
    break;

  case 36:
#line 326 "compiler_hw3.y"
         {(yyval.string)="REM";}
#line 1914 "y.tab.c"
    break;

  case 37:
#line 330 "compiler_hw3.y"
         {(yyval.string)="POS";}
#line 1920 "y.tab.c"
    break;

  case 38:
#line 331 "compiler_hw3.y"
         {(yyval.string)="NEG";}
#line 1926 "y.tab.c"
    break;

  case 39:
#line 332 "compiler_hw3.y"
         {(yyval.string)="NOT";}
#line 1932 "y.tab.c"
    break;

  case 40:
#line 337 "compiler_hw3.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1938 "y.tab.c"
    break;

  case 41:
#line 338 "compiler_hw3.y"
               {(yyval.string)=(yyvsp[0].string);fprintf(file,"\t%caload\n",(yyvsp[0].string)[0]);}
#line 1944 "y.tab.c"
    break;

  case 42:
#line 339 "compiler_hw3.y"
                    {(yyval.string)=(yyvsp[0].string);}
#line 1950 "y.tab.c"
    break;

  case 43:
#line 343 "compiler_hw3.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1956 "y.tab.c"
    break;

  case 44:
#line 344 "compiler_hw3.y"
           {
		int address=lookup_symbol((yyvsp[0].string),tail);
		bool is_array=0;
		(yyval.string)=find_type((yyvsp[0].string),&foo,&is_array);
		if((yyval.string)[0]=='s'||is_array)	
			fprintf(file,"\taload %d\n",address);
		else if((yyval.string)[0]=='b')
			fprintf(file,"\tiload %d\n",address);
		else
			fprintf(file,"\t%cload %d\n",(yyval.string)[0],address);
		
	}
#line 1973 "y.tab.c"
    break;

  case 45:
#line 356 "compiler_hw3.y"
                                   {(yyval.string)=(yyvsp[-1].string);}
#line 1979 "y.tab.c"
    break;

  case 46:
#line 360 "compiler_hw3.y"
             {fprintf(file,"\tldc %d\n",(yyvsp[0].i_val));printf("INT_LIT %d\n",(yyvsp[0].i_val));(yyval.string)="int32";}
#line 1985 "y.tab.c"
    break;

  case 47:
#line 361 "compiler_hw3.y"
               {fprintf(file,"\tldc %f\n",(yyvsp[0].f_val));printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));(yyval.string)="float32";}
#line 1991 "y.tab.c"
    break;

  case 48:
#line 362 "compiler_hw3.y"
              {fprintf(file,"\tldc %d\n",(yyvsp[0].b_val));printf("BOOL_LIT %d\n",(yyvsp[0].b_val));(yyval.string)="bool";}
#line 1997 "y.tab.c"
    break;

  case 49:
#line 363 "compiler_hw3.y"
                {fprintf(file,"\tldc \"%s\"\n",(yyvsp[0].string));printf("STRING_LIT %s\n",(yyvsp[0].string));(yyval.string)="string";}
#line 2003 "y.tab.c"
    break;

  case 50:
#line 364 "compiler_hw3.y"
              {fprintf(file,"\ticonst_1\n");printf("TRUE\n");(yyval.string)="bool";}
#line 2009 "y.tab.c"
    break;

  case 51:
#line 365 "compiler_hw3.y"
               {fprintf(file,"\ticonst_0\n");printf("FALSE\n");(yyval.string)="bool";}
#line 2015 "y.tab.c"
    break;

  case 52:
#line 370 "compiler_hw3.y"
                                          {
		(yyval.string)=(yyvsp[-3].string);
	}
#line 2023 "y.tab.c"
    break;

  case 53:
#line 377 "compiler_hw3.y"
                                    {
		(yyval.string)=(yyvsp[-3].string);
		if(!strcmp((yyvsp[-3].string),(yyvsp[-1].string))){
			printf("error:%d: covert the same type",yylineno);
			HAS_ERROR=1;
		}
		else if(!strcmp((yyvsp[-3].string),"float32")&&!strcmp((yyvsp[-1].string),"int32")){
			fprintf(file,"\ti2f\n");
		}
		else if(!strcmp((yyvsp[-3].string),"int32")&&!strcmp((yyvsp[-1].string),"float32")){
			fprintf(file,"\tf2i\n");
		}
		else{
			printf("error:%d: cannot convert type %s to type %s",yylineno,(yyvsp[-1].string),(yyvsp[-3].string));
			HAS_ERROR=1;
		}
		printf("%c to %c\n",toupper((yyvsp[-1].string)[0]),toupper((yyvsp[-3].string)[0]));
	}
#line 2046 "y.tab.c"
    break;

  case 64:
#line 416 "compiler_hw3.y"
                                      {
		strcpy(_var,(yyvsp[-2].string));
		int address;
		if((yyvsp[-1].string)[0]=='a'){
			address=create_symbol(_var,"array",_type+1);
			fprintf(file,"\tastore %d\n",address);				
		}
		else{
			if(!(yyvsp[0].b_val)){
				if((yyvsp[-1].string)[0]=='i'||(yyvsp[-1].string)[0]=='b')
					fprintf(file,"\tldc 0\n");
				else if((yyvsp[-1].string)[0]=='f')
					fprintf(file,"\tldc 0.0\n");
				else//string
					fprintf(file,"\tldc \"\"\n");
			}
			strcpy(_type,(yyvsp[-1].string));
			address=create_symbol(_var,_type,"-");				
			if((yyvsp[-1].string)[0]=='s')
				fprintf(file,"\tastore %d\n",address);
			else if((yyvsp[-1].string)[0]=='b')
				fprintf(file,"\tistore %d\n",address);
			else
				fprintf(file,"\t%cstore %d\n",(yyvsp[-1].string)[0],address);
		}
	}
#line 2077 "y.tab.c"
    break;

  case 65:
#line 445 "compiler_hw3.y"
                       {(yyval.b_val)=1;}
#line 2083 "y.tab.c"
    break;

  case 66:
#line 446 "compiler_hw3.y"
     {(yyval.b_val)=0;}
#line 2089 "y.tab.c"
    break;

  case 67:
#line 450 "compiler_hw3.y"
                                         {	
		if(strlen((yyvsp[-1].string))==10){//except ASSIGN
			if((yyvsp[-2].string)[0]=='s'||l_array)	
				fprintf(file,"\taload %d\n",l_address);
			else if((yyvsp[-2].string)[0]=='i'||(yyvsp[-2].string)[0]=='b')
				fprintf(file,"\tiload %d\n",l_address);
			else if((yyvsp[-2].string)[0]=='f')
				fprintf(file,"\tfload %d\n",l_address);
			fprintf(file,"\tswap\n");
			char* temp_op = lower_substr((yyvsp[-1].string),3);
			fprintf(file,"\t%c%s\n",(yyvsp[-2].string)[0],temp_op);
			free(temp_op);
		}
		if(l_array){
			fprintf(file,"\t%castore\n",(yyvsp[-2].string)[0]);
			l_array=0;//reset to default	
		}
		else if((yyvsp[-2].string)[0]=='s')
			fprintf(file,"\tastore %d\n",l_address);
		else if((yyvsp[-2].string)[0]=='b')
			fprintf(file,"\tistore %d\n",l_address);
		else{
			fprintf(file,"\t%cstore %d\n",(yyvsp[-2].string)[0],l_address);
		}

		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[-2].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-1].string),"REM_ASSIGN")&&(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32"))){	
			HAS_ERROR=1;
			printf("error:%d: invalid operation: (operator REM_ASSIGN not defined on float32)\n",yylineno);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){
			HAS_ERROR=1;
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
		}
		else if(left_value_error){
			printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].string));
			HAS_ERROR=1;
			left_value_error=0;
		}
		printf("%s\n",(yyvsp[-1].string));
	}
#line 2137 "y.tab.c"
    break;

  case 68:
#line 496 "compiler_hw3.y"
                  {(yyval.string)=(yyvsp[0].string);l_array=1;}
#line 2143 "y.tab.c"
    break;

  case 69:
#line 497 "compiler_hw3.y"
                {(yyval.string)=(yyvsp[0].string);left_value_error=1;}
#line 2149 "y.tab.c"
    break;

  case 70:
#line 498 "compiler_hw3.y"
              {
		bool is_array=0;
		(yyval.string)=find_type((yyvsp[0].string),&foo,&is_array);
		l_address=lookup_symbol((yyvsp[0].string),tail);
	}
#line 2159 "y.tab.c"
    break;

  case 71:
#line 506 "compiler_hw3.y"
             {(yyval.string)="ASSIGN";}
#line 2165 "y.tab.c"
    break;

  case 72:
#line 507 "compiler_hw3.y"
                 {(yyval.string)="ADD_ASSIGN";}
#line 2171 "y.tab.c"
    break;

  case 73:
#line 508 "compiler_hw3.y"
                 {(yyval.string)="SUB_ASSIGN";}
#line 2177 "y.tab.c"
    break;

  case 74:
#line 509 "compiler_hw3.y"
                 {(yyval.string)="MUL_ASSIGN";}
#line 2183 "y.tab.c"
    break;

  case 75:
#line 510 "compiler_hw3.y"
                 {(yyval.string)="DIV_ASSIGN";}
#line 2189 "y.tab.c"
    break;

  case 76:
#line 511 "compiler_hw3.y"
                 {(yyval.string)="REM_ASSIGN";}
#line 2195 "y.tab.c"
    break;

  case 77:
#line 516 "compiler_hw3.y"
                   {
	if((yyvsp[0].string)[0]=='s'||l_array)	
		fprintf(file,"\taload %d\n",l_address);
	else if((yyvsp[0].string)[0]=='i')
		fprintf(file,"\tiload %d\n\tldc 1\n",l_address);
	else if((yyvsp[0].string)[0]=='f')
		fprintf(file,"\tfload %d\n\tldc 1.0\n",l_address);
	else
		fprintf(file,"\terror for IncDec\n");
	}
#line 2210 "y.tab.c"
    break;

  case 78:
#line 525 "compiler_hw3.y"
                {
		fprintf(file,"\t%c%s\n",(yyvsp[-2].string)[0],(yyvsp[0].string));
		if(l_array){
			fprintf(file,"\t%castore\n",(yyvsp[-2].string)[0]);
			l_array=0;//reset to default	
		}
		else{
			fprintf(file,"\t%cstore %d\n",(yyvsp[-2].string)[0],l_address);
		}
	}
#line 2225 "y.tab.c"
    break;

  case 79:
#line 538 "compiler_hw3.y"
         {printf("INC\n");(yyval.string)="add";}
#line 2231 "y.tab.c"
    break;

  case 80:
#line 539 "compiler_hw3.y"
         {printf("DEC\n");(yyval.string)="sub";}
#line 2237 "y.tab.c"
    break;

  case 81:
#line 544 "compiler_hw3.y"
            {++scope;}
#line 2243 "y.tab.c"
    break;

  case 82:
#line 544 "compiler_hw3.y"
                                    {dump_symbol(tail);}
#line 2249 "y.tab.c"
    break;

  case 83:
#line 544 "compiler_hw3.y"
                                                               {--scope;}
#line 2255 "y.tab.c"
    break;

  case 84:
#line 550 "compiler_hw3.y"
                {fprintf(file,"\nL%d_if_exit_%d:\n",scope,if_exit_num[scope]++);}
#line 2261 "y.tab.c"
    break;

  case 86:
#line 552 "compiler_hw3.y"
                            {
		fprintf(file,"\nL%d_if_exit_%d:\n",scope,if_exit_num[scope]++);
	}
#line 2269 "y.tab.c"
    break;

  case 87:
#line 558 "compiler_hw3.y"
                     {
		fprintf(file,"\tifeq L%d_if_%d\n",scope,if_num[scope]);//if false, jump
	}
#line 2277 "y.tab.c"
    break;

  case 88:
#line 563 "compiler_hw3.y"
                       {	
		fprintf(file,"\tgoto L%d_if_exit_%d\n",scope,if_exit_num[scope]);//after if block
		fprintf(file,"\nL%d_if_%d:\n",scope,if_num[scope]++);		
	}
#line 2286 "y.tab.c"
    break;

  case 89:
#line 568 "compiler_hw3.y"
                {
		if(strcmp((yyvsp[0].string),"bool")){
			HAS_ERROR=1;
			printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,(yyvsp[0].string));
		}
	}
#line 2297 "y.tab.c"
    break;

  case 90:
#line 579 "compiler_hw3.y"
         {fprintf(file,"L%d_for_begin%d:\n",scope,for_num[scope]);}
#line 2303 "y.tab.c"
    break;

  case 91:
#line 579 "compiler_hw3.y"
                                                                                      {
	fprintf(file,"\tgoto L%d_for_begin%d\n",scope,for_num[scope]);
	fprintf(file,"L%d_for_exit%d:\n",scope,for_num[scope]);
	++for_num[scope];	
}
#line 2313 "y.tab.c"
    break;

  case 92:
#line 587 "compiler_hw3.y"
               {fprintf(file,"\tifeq L%d_for_exit%d\n",scope,for_num[scope]);}
#line 2319 "y.tab.c"
    break;

  case 94:
#line 592 "compiler_hw3.y"
                        {fprintf(file,"L%d_for_begin%d:\n",scope,++for_num[scope]);}
#line 2325 "y.tab.c"
    break;

  case 95:
#line 592 "compiler_hw3.y"
                                                                                              {
		fprintf(file,"\tifeq L%d_for_exit%d\n",scope,for_num[scope]+1);
		fprintf(file,"\tgoto L%d_for_stmt%d\n",scope,for_num[scope]);
	}
#line 2334 "y.tab.c"
    break;

  case 96:
#line 596 "compiler_hw3.y"
         {fprintf(file,"L%d_for_begin%d:\n",scope,++for_num[scope]);}
#line 2340 "y.tab.c"
    break;

  case 97:
#line 596 "compiler_hw3.y"
                                                                             {
		fprintf(file,"\tgoto L%d_for_begin%d\n",scope,for_num[scope]-1);
		fprintf(file,"L%d_for_stmt%d:\n",scope,for_num[scope]-1);
	}
#line 2349 "y.tab.c"
    break;

  case 100:
#line 612 "compiler_hw3.y"
                                            {
		char print_type;
		if(!strcmp((yyvsp[-1].string),"bool")){
			print_type='Z';
			fprintf(file,"\tifne L%d_cmp_%d\n",scope,cmp_number++);
			fprintf(file,"\tldc \"false\"\n\tgoto L%d_cmp_%d\n",scope,cmp_number);
			fprintf(file,"L%d_cmp_%d:\n\tldc \"true\"\n",scope,cmp_number-1);
			fprintf(file,"L%d_cmp_%d:\n",scope,cmp_number++);
			
		}
		else
			print_type=toupper((yyvsp[-1].string)[0]);
		printf("%s %s\n",(yyvsp[-3].string),(yyvsp[-1].string));
		fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
		char* temp_type=lower_str((yyvsp[-3].string));
		if(print_type=='Z'||print_type=='S')
			fprintf(file,"\tinvokevirtual java/io/PrintStream/%s(Ljava/lang/String;)V\n\n",temp_type);
		else 
			fprintf(file,"\tinvokevirtual java/io/PrintStream/%s(%c)V\n\n",temp_type,print_type);
		free(temp_type);
	}
#line 2375 "y.tab.c"
    break;

  case 101:
#line 636 "compiler_hw3.y"
           {(yyval.string)="PRINT";}
#line 2381 "y.tab.c"
    break;

  case 102:
#line 637 "compiler_hw3.y"
             {(yyval.string)="PRINTLN";}
#line 2387 "y.tab.c"
    break;


#line 2391 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 639 "compiler_hw3.y"

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
