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
#line 2 "compiler_hw2.y"

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
	void pop_till_target(op_stack** top,char* target);
	char* find_type(char* id,int* line);
	/*initialize the head of symbol table*/
	stb* tail = NULL;
	
	op_stack* stack_top=NULL;
	char _type [9];
	char _var [128];
	char _etype [7];

#line 139 "compiler_hw2.tab.c"

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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "compiler_hw2.y"

    int i_val;
    float f_val;
    char* string;
    bool b_val;

#line 250 "compiler_hw2.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   125,   126,   131,   132,   144,   145,   146,
     147,   151,   154,   156,   165,   179,   182,   202,   205,   215,
     218,   231,   234,   250,   253,   254,   265,   268,   271,   272,
     273,   274,   275,   276,   280,   281,   285,   286,   287,   291,
     292,   293,   298,   299,   300,   304,   305,   306,   310,   312,
     314,   315,   316,   317,   318,   319,   324,   329,   334,   335,
     336,   337,   338,   339,   340,   344,   345,   346,   351,   365,
     366,   371,   390,   400,   401,   402,   403,   404,   405,   410,
     414,   415,   420,   420,   420,   430,   430,   434,   443,   444,
     448,   449,   455,   459,   460,   464,   464,   464,   468,   472,
     477,   481,   482
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "QUOTA", "NEWLINE", "ADD",
  "SUB", "MUL", "QUO", "MOD", "INC", "DEC", "REM", "POS", "NEG", "LSS",
  "GTR", "LEQ", "GEQ", "EQL", "NEQ", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NOT", "TRUE",
  "FALSE", "IF", "ELSE", "FOR", "VAR", "PRINT", "PRINTLN", "IDENT", "INT",
  "FLOAT", "BOOL", "STRING", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "BOOL_LIT", "$accept", "Program", "StatementList", "Type", "TypeName",
  "ArrayType", "LBR", "RBR", "Expression", "B1", "B2", "B3", "B4",
  "UnaryExpr", "LA", "LO", "Cmp_op", "Add_op", "Mul_op", "Unary_op",
  "PrimaryExpr", "Operand", "LPA", "RPA", "Literal", "IndexExpr",
  "ConversionExpr", "Statement", "SimpleStmt", "DeclarationStmt",
  "DeclarationAssign", "AssignmentStmt", "ExpressionVar", "Assign_op",
  "IncDecStmt", "IncDec", "Block", "$@1", "$@2", "IfStmt", "$@3",
  "Condition", "OptionalIfStmt", "ElseIfStmt", "ForStmt", "ForCondition",
  "ForClause", "$@4", "$@5", "InitStmt", "PosStmt", "PrintStmt",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-88)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      95,   -57,    21,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      21,    21,   -31,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    16,    95,    22,   -57,   -57,    75,
       4,    -5,    28,    46,   -57,    21,    31,   -57,    21,   -57,
     -57,   -57,   -57,    41,    43,   -57,    -2,   -57,    44,    51,
      52,    64,    30,     2,    95,     7,   -57,    77,   -57,   -57,
      70,   -57,   -57,     1,   -57,   -57,    21,   -57,   -57,   -57,
      21,   -57,   -57,    21,   -57,   -57,   -57,   -57,   -57,   -57,
      21,   -57,   -57,    21,   -57,   -57,   -57,    21,   -57,   -57,
      21,     8,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      21,   -57,   -57,   -57,   -57,    21,     1,    95,    70,   -57,
      69,    50,     9,     4,    -5,    28,    46,   -57,    11,   -57,
     -57,     7,    10,   -57,    72,   -57,    21,    21,   -57,   -57,
     -57,   -57,   -57,   -57,    42,   -57,     7,     0,    79,   -57,
     -57,   -57,    21,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    48,     0,    82,    64,    39,    40,    41,    54,    55,
       0,     0,     0,   101,   102,    46,     7,     8,    10,     9,
      50,    51,    53,    52,     0,     2,     0,     5,     6,    72,
      15,    17,    19,    21,    23,     0,    24,    42,     0,    45,
      43,    44,     4,     0,     0,    65,     0,    67,     0,     0,
       0,     0,     0,     0,     0,    87,    85,    72,    98,    93,
       0,    94,    95,     0,     1,     3,     0,    80,    81,    27,
       0,    79,    26,     0,    30,    32,    31,    33,    28,    29,
       0,    34,    35,     0,    36,    37,    38,     0,    25,    12,
       0,     0,    59,    58,    73,    74,    75,    76,    77,    78,
       0,    60,    61,    62,    63,     0,     0,    83,     0,    92,
       0,    70,     0,    14,    16,    18,    20,    22,     0,    49,
      47,    71,     0,    11,     0,    91,     0,     0,    68,    57,
      13,    56,   100,    84,    86,    96,    69,     0,     0,    89,
      88,    90,     0,    99,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,    36,   -52,   -57,   -57,   -57,   -57,    -1,    27,
      18,    12,    20,   -30,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -22,   -11,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -56,   -57,   -57,   -36,
     -57,    -9,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    90,   131,    29,    30,
      31,    32,    33,    34,    73,    70,    80,    83,    87,    35,
      36,    37,    38,   120,    39,    40,    41,    42,    43,    44,
     128,    45,    46,   100,    47,    71,    48,    54,   124,    49,
     108,    56,   141,   134,    50,    60,    61,   110,   138,    62,
     144,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    53,    59,    65,   109,    88,     2,     3,   106,    55,
      57,   111,   119,   129,   132,    63,    64,   130,    74,    75,
      76,    77,    78,    79,     1,    66,     2,    94,    95,    96,
      97,    98,    99,   105,     5,     6,    89,    91,    69,    72,
      10,    81,    82,    69,    69,    69,    69,    69,    16,    17,
      18,    19,   125,    92,   123,    93,   101,   117,     7,     8,
       9,    84,    85,   102,   103,   112,    86,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   104,     3,   126,   127,
     133,   139,   -66,   137,   -87,    65,   -66,   -66,   142,   118,
     107,   114,   115,    67,    68,    67,    68,   113,     1,   121,
       2,   140,     3,   116,   122,     0,     0,     4,     5,     6,
       0,    69,     0,    69,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,    55,   136,     0,     0,     0,
       0,   143,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23
};

static const yytype_int16 yycheck[] =
{
      11,     2,    11,    25,    60,    35,     5,     7,     6,    10,
      11,    63,     4,     4,     4,    46,     0,     6,    23,    24,
      25,    26,    27,    28,     3,     3,     5,    29,    30,    31,
      32,    33,    34,     3,    13,    14,     5,    38,    36,    35,
      40,    13,    14,    36,    36,    36,    36,    36,    47,    48,
      49,    50,   108,    12,   106,    12,    12,    87,    37,    38,
      39,    15,    16,    12,    12,    66,    20,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    12,     7,     9,    29,
       8,   137,     7,    41,     7,   107,     9,    12,     9,    90,
      54,    73,    80,    18,    19,    18,    19,    70,     3,   100,
       5,   137,     7,    83,   105,    -1,    -1,    12,    13,    14,
      -1,    36,    -1,    36,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,   142,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,    12,    13,    14,    37,    38,    39,
      40,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    56,    57,    58,    59,    60,    63,
      64,    65,    66,    67,    68,    74,    75,    76,    77,    79,
      80,    81,    82,    83,    84,    86,    87,    89,    91,    94,
      99,   106,   107,    63,    92,    63,    96,    63,    83,    96,
     100,   101,   104,    46,     0,    82,     3,    18,    19,    36,
      70,    90,    35,    69,    23,    24,    25,    26,    27,    28,
      71,    13,    14,    72,    15,    16,    20,    73,    68,     5,
      61,    63,    12,    12,    29,    30,    31,    32,    33,    34,
      88,    12,    12,    12,    12,     3,     6,    57,    95,    91,
     102,    58,    63,    64,    65,    66,    67,    68,    63,     4,
      78,    63,    63,    58,    93,    91,     9,    29,    85,     4,
       6,    62,     4,     8,    98,    96,    63,    41,   103,    91,
      94,    97,     9,    83,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    60,    61,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    75,    76,    76,    76,    77,    78,
      79,    79,    79,    79,    79,    79,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    85,
      85,    86,    87,    88,    88,    88,    88,    88,    88,    89,
      90,    90,    92,    93,    91,    95,    94,    96,    97,    97,
      98,    98,    99,   100,   100,   102,   103,   101,   104,   105,
     106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     4,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     0,     5,     0,     5,     1,     1,     1,
       3,     0,     3,     1,     1,     0,     0,     7,     1,     1,
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
#line 131 "compiler_hw2.y"
              {(yyval.string)=(yyvsp[0].string);}
#line 1547 "compiler_hw2.tab.c"
    break;

  case 6:
#line 132 "compiler_hw2.y"
               {
		//$$="array";
		_type[0]='a';
		//printf("test  %d cececcec\n",strlen($1));
//		strcpy(_etype,$1);
		strncpy(_type+1,(yyvsp[0].string),strlen((yyvsp[0].string)));
		//printf("test    %s!!!!!!!!11\n",_type);
		(yyval.string)=_type;
	}
#line 1561 "compiler_hw2.tab.c"
    break;

  case 7:
#line 144 "compiler_hw2.y"
          {(yyval.string)=(yyvsp[0].string);}
#line 1567 "compiler_hw2.tab.c"
    break;

  case 8:
#line 145 "compiler_hw2.y"
            {(yyval.string)=(yyvsp[0].string);}
#line 1573 "compiler_hw2.tab.c"
    break;

  case 9:
#line 146 "compiler_hw2.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1579 "compiler_hw2.tab.c"
    break;

  case 10:
#line 147 "compiler_hw2.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1585 "compiler_hw2.tab.c"
    break;

  case 11:
#line 151 "compiler_hw2.y"
                                     {(yyval.string)=(yyvsp[0].string);}
#line 1591 "compiler_hw2.tab.c"
    break;

  case 12:
#line 154 "compiler_hw2.y"
               {stack(&stack_top,"[");}
#line 1597 "compiler_hw2.tab.c"
    break;

  case 13:
#line 156 "compiler_hw2.y"
               {stack(&stack_top,"]");}
#line 1603 "compiler_hw2.tab.c"
    break;

  case 14:
#line 165 "compiler_hw2.y"
                      {

		pop_till_target(&stack_top,"LOR");	
		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[-2].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32")){	
			printf("error:%d: invalid operation: (operator LOR not defined on float32)\n",yylineno);
		}
		else if(!strcmp((yyvsp[-2].string),"int32")||!strcmp((yyvsp[0].string),"int32")){		
			printf("error:%d: invalid operation: (operator LOR not defined on int32)\n",yylineno);
		}
		(yyval.string)="bool";		
	}
#line 1622 "compiler_hw2.tab.c"
    break;

  case 15:
#line 179 "compiler_hw2.y"
            {(yyval.string)=(yyvsp[0].string);}
#line 1628 "compiler_hw2.tab.c"
    break;

  case 16:
#line 182 "compiler_hw2.y"
                 {

		//pop_till_target(&stack_top,$2);	
		//pop_till_target(&stack_top,"LORAND");	
		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32")){	
			printf("error:%d: invalid operation: (operator LAND not defined on float32)\n",yylineno);
		}
		else if(!strcmp((yyvsp[-2].string),"int32")||!strcmp((yyvsp[0].string),"int32")){		
			printf("error:%d: invalid operation: (operator LAND not defined on int32)\n",yylineno);
		}
		
		
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
		}
		(yyval.string)="bool";
	}
#line 1653 "compiler_hw2.tab.c"
    break;

  case 17:
#line 202 "compiler_hw2.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1659 "compiler_hw2.tab.c"
    break;

  case 18:
#line 205 "compiler_hw2.y"
                     {
		//pop_till_target(&stack_top,$2);	
		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
		}
		(yyval.string)="bool";
	}
#line 1674 "compiler_hw2.tab.c"
    break;

  case 19:
#line 215 "compiler_hw2.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1680 "compiler_hw2.tab.c"
    break;

  case 20:
#line 218 "compiler_hw2.y"
                     {
		pop_till_target(&stack_top,(yyvsp[-1].string));		
		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			(yyval.string)="float32";//conversion
		}
		else{
			(yyval.string)=(yyvsp[-2].string);
		}
	}
#line 1698 "compiler_hw2.tab.c"
    break;

  case 21:
#line 231 "compiler_hw2.y"
           {(yyval.string)=(yyvsp[0].string);}
#line 1704 "compiler_hw2.tab.c"
    break;

  case 22:
#line 234 "compiler_hw2.y"
                            {	
		pop_till_target(&stack_top,(yyvsp[-1].string));	

		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[0].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-1].string),"REM")&&(!(strcmp((yyvsp[-2].string),"float32"))||!(strcmp((yyvsp[0].string),"float32")))){	
			printf("error:%d: invalid operation: (operator REM not defined on float32)\n",yylineno);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){	
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
			(yyval.string)="float32";//conversion
		}
		else
			(yyval.string)=(yyvsp[-2].string);
	}
#line 1725 "compiler_hw2.tab.c"
    break;

  case 23:
#line 250 "compiler_hw2.y"
                  {(yyval.string)=find_type((yyvsp[0].string),&foo);}
#line 1731 "compiler_hw2.tab.c"
    break;

  case 24:
#line 253 "compiler_hw2.y"
                 {(yyval.string)=(yyvsp[0].string);}
#line 1737 "compiler_hw2.tab.c"
    break;

  case 25:
#line 254 "compiler_hw2.y"
                        {(yyval.string)=(yyvsp[0].string);}
#line 1743 "compiler_hw2.tab.c"
    break;

  case 26:
#line 265 "compiler_hw2.y"
             {(yyval.string)="LAND";stack(&stack_top,"LAND");}
#line 1749 "compiler_hw2.tab.c"
    break;

  case 27:
#line 268 "compiler_hw2.y"
            {(yyval.string)="LOR";stack(&stack_top,"LOR");}
#line 1755 "compiler_hw2.tab.c"
    break;

  case 28:
#line 271 "compiler_hw2.y"
         {stack(&stack_top,"EQL");}
#line 1761 "compiler_hw2.tab.c"
    break;

  case 29:
#line 272 "compiler_hw2.y"
         {stack(&stack_top,"NEQ");}
#line 1767 "compiler_hw2.tab.c"
    break;

  case 30:
#line 273 "compiler_hw2.y"
         {stack(&stack_top,"LSS");}
#line 1773 "compiler_hw2.tab.c"
    break;

  case 31:
#line 274 "compiler_hw2.y"
         {stack(&stack_top,"LEQ");}
#line 1779 "compiler_hw2.tab.c"
    break;

  case 32:
#line 275 "compiler_hw2.y"
         {stack(&stack_top,"GTR");}
#line 1785 "compiler_hw2.tab.c"
    break;

  case 33:
#line 276 "compiler_hw2.y"
         {stack(&stack_top,"GEQ");}
#line 1791 "compiler_hw2.tab.c"
    break;

  case 34:
#line 280 "compiler_hw2.y"
         {stack(&stack_top,"ADD");(yyval.string)="ADD";}
#line 1797 "compiler_hw2.tab.c"
    break;

  case 35:
#line 281 "compiler_hw2.y"
         {stack(&stack_top,"SUB");(yyval.string)="SUB";}
#line 1803 "compiler_hw2.tab.c"
    break;

  case 36:
#line 285 "compiler_hw2.y"
         {stack(&stack_top,"MUL");(yyval.string)="MUL";}
#line 1809 "compiler_hw2.tab.c"
    break;

  case 37:
#line 286 "compiler_hw2.y"
         {stack(&stack_top,"QUO");(yyval.string)="QUO";}
#line 1815 "compiler_hw2.tab.c"
    break;

  case 38:
#line 287 "compiler_hw2.y"
         {stack(&stack_top,"REM");(yyval.string)="REM";}
#line 1821 "compiler_hw2.tab.c"
    break;

  case 39:
#line 291 "compiler_hw2.y"
         {stack(&stack_top,"POS");}
#line 1827 "compiler_hw2.tab.c"
    break;

  case 40:
#line 292 "compiler_hw2.y"
         {stack(&stack_top,"NEG");}
#line 1833 "compiler_hw2.tab.c"
    break;

  case 41:
#line 293 "compiler_hw2.y"
         {stack(&stack_top,"NOT");}
#line 1839 "compiler_hw2.tab.c"
    break;

  case 42:
#line 298 "compiler_hw2.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1845 "compiler_hw2.tab.c"
    break;

  case 43:
#line 299 "compiler_hw2.y"
               {(yyval.string)=(yyvsp[0].string);}
#line 1851 "compiler_hw2.tab.c"
    break;

  case 44:
#line 300 "compiler_hw2.y"
                    {(yyval.string)=(yyvsp[0].string);}
#line 1857 "compiler_hw2.tab.c"
    break;

  case 45:
#line 304 "compiler_hw2.y"
             {(yyval.string)=(yyvsp[0].string);}
#line 1863 "compiler_hw2.tab.c"
    break;

  case 46:
#line 305 "compiler_hw2.y"
           {lookup_symbol((yyvsp[0].string),tail);(yyval.string)=find_type((yyvsp[0].string),&foo);var_flag=1;}
#line 1869 "compiler_hw2.tab.c"
    break;

  case 47:
#line 306 "compiler_hw2.y"
                             {(yyval.string)=(yyvsp[-1].string);}
#line 1875 "compiler_hw2.tab.c"
    break;

  case 48:
#line 310 "compiler_hw2.y"
               {stack(&stack_top,"(");}
#line 1881 "compiler_hw2.tab.c"
    break;

  case 49:
#line 312 "compiler_hw2.y"
               {stack(&stack_top,")");}
#line 1887 "compiler_hw2.tab.c"
    break;

  case 50:
#line 314 "compiler_hw2.y"
             {printf("INT_LIT %d\n",(yyvsp[0].i_val));(yyval.string)="int32";}
#line 1893 "compiler_hw2.tab.c"
    break;

  case 51:
#line 315 "compiler_hw2.y"
               {printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));(yyval.string)="float32";}
#line 1899 "compiler_hw2.tab.c"
    break;

  case 52:
#line 316 "compiler_hw2.y"
              {printf("BOOL_LIT %d\n",(yyvsp[0].b_val));(yyval.string)="bool";}
#line 1905 "compiler_hw2.tab.c"
    break;

  case 53:
#line 317 "compiler_hw2.y"
                {printf("STRING_LIT %s\n",(yyvsp[0].string));(yyval.string)="string";}
#line 1911 "compiler_hw2.tab.c"
    break;

  case 54:
#line 318 "compiler_hw2.y"
              {printf("TRUE\n");(yyval.string)="bool";}
#line 1917 "compiler_hw2.tab.c"
    break;

  case 55:
#line 319 "compiler_hw2.y"
               {printf("FALSE\n");(yyval.string)="bool";}
#line 1923 "compiler_hw2.tab.c"
    break;

  case 56:
#line 324 "compiler_hw2.y"
                                    {(yyval.string)=(yyvsp[-3].string);}
#line 1929 "compiler_hw2.tab.c"
    break;

  case 57:
#line 329 "compiler_hw2.y"
                                    {(yyval.string)=(yyvsp[-3].string);printf("%c to %c\n",toupper((yyvsp[-1].string)[0]),toupper((yyvsp[-3].string)[0]));}
#line 1935 "compiler_hw2.tab.c"
    break;

  case 58:
#line 334 "compiler_hw2.y"
                             {stack(&stack_top,"#");}
#line 1941 "compiler_hw2.tab.c"
    break;

  case 59:
#line 335 "compiler_hw2.y"
                        {stack(&stack_top,"#");}
#line 1947 "compiler_hw2.tab.c"
    break;

  case 65:
#line 344 "compiler_hw2.y"
                    {var_flag=0;}
#line 1953 "compiler_hw2.tab.c"
    break;

  case 68:
#line 351 "compiler_hw2.y"
                                      {
		strcpy(_var,(yyvsp[-2].string));

		if((yyvsp[-1].string)[0]=='a'){
			create_symbol(_var,"array",_type+1);				
		}
		else{
			strcpy(_type,(yyvsp[-1].string));
			create_symbol(_var,_type,"-");				
		}
	}
#line 1969 "compiler_hw2.tab.c"
    break;

  case 71:
#line 371 "compiler_hw2.y"
                                        {	
		if(!strcmp((yyvsp[-2].string),"unknown")||!strcmp((yyvsp[-2].string),"unknown")){
			//printf("error:%d: undefined: %s\n",yylineno,id);
		}
		else if(!strcmp((yyvsp[-1].string),"REM_ASSIGN")&&(!strcmp((yyvsp[-2].string),"float32")||!strcmp((yyvsp[0].string),"float32"))){	
			printf("error:%d: invalid operation: (operator REM_ASSIGN not defined on float32)\n",yylineno);
		}
		else if(strcmp((yyvsp[-2].string),(yyvsp[0].string))){
			printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n",yylineno,(yyvsp[-1].string),(yyvsp[-2].string),(yyvsp[0].string));
		}
		else if(left_value_error){

			printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].string));
			left_value_error=0;
		}
	}
#line 1990 "compiler_hw2.tab.c"
    break;

  case 72:
#line 390 "compiler_hw2.y"
                    {
		if(!var_flag){
			
			left_value_error=1;
			var_flag=0;
		}
		(yyval.string)=(yyvsp[0].string);
	}
#line 2003 "compiler_hw2.tab.c"
    break;

  case 73:
#line 400 "compiler_hw2.y"
             {stack(&stack_top,"ASSIGN");(yyval.string)="ASSIGN";}
#line 2009 "compiler_hw2.tab.c"
    break;

  case 74:
#line 401 "compiler_hw2.y"
                 {stack(&stack_top,"ADD_ASSIGN");(yyval.string)="ADD_ASSIGN";}
#line 2015 "compiler_hw2.tab.c"
    break;

  case 75:
#line 402 "compiler_hw2.y"
                 {stack(&stack_top,"SUB_ASSIGN");(yyval.string)="SUB_ASSIGN";}
#line 2021 "compiler_hw2.tab.c"
    break;

  case 76:
#line 403 "compiler_hw2.y"
                 {stack(&stack_top,"MUL_ASSIGN");(yyval.string)="MUL_ASSIGN";}
#line 2027 "compiler_hw2.tab.c"
    break;

  case 77:
#line 404 "compiler_hw2.y"
                 {stack(&stack_top,"QUO_ASSIGN");(yyval.string)="QUO_ASSIGN";}
#line 2033 "compiler_hw2.tab.c"
    break;

  case 78:
#line 405 "compiler_hw2.y"
                 {stack(&stack_top,"REM_ASSIGN");(yyval.string)="REM_ASSIGN";}
#line 2039 "compiler_hw2.tab.c"
    break;

  case 82:
#line 420 "compiler_hw2.y"
            {++scope;}
#line 2045 "compiler_hw2.tab.c"
    break;

  case 83:
#line 420 "compiler_hw2.y"
                                    {dump_symbol(tail);}
#line 2051 "compiler_hw2.tab.c"
    break;

  case 84:
#line 420 "compiler_hw2.y"
                                                               {--scope;}
#line 2057 "compiler_hw2.tab.c"
    break;

  case 85:
#line 430 "compiler_hw2.y"
                  {stack(&stack_top,"#");}
#line 2063 "compiler_hw2.tab.c"
    break;

  case 87:
#line 434 "compiler_hw2.y"
                {
		stack(&stack_top,"#");
		if(strcmp((yyvsp[0].string),"bool")){
			printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,(yyvsp[0].string));
		}
	}
#line 2074 "compiler_hw2.tab.c"
    break;

  case 93:
#line 459 "compiler_hw2.y"
               {stack(&stack_top,"#");}
#line 2080 "compiler_hw2.tab.c"
    break;

  case 95:
#line 464 "compiler_hw2.y"
              {stack(&stack_top,"#");}
#line 2086 "compiler_hw2.tab.c"
    break;

  case 96:
#line 464 "compiler_hw2.y"
                                                          {stack(&stack_top,"#");}
#line 2092 "compiler_hw2.tab.c"
    break;

  case 97:
#line 464 "compiler_hw2.y"
                                                                                                    {stack(&stack_top,"#");}
#line 2098 "compiler_hw2.tab.c"
    break;

  case 100:
#line 477 "compiler_hw2.y"
                                        {stack(&stack_top,"#");printf("%s %s\n",(yyvsp[-3].string),(yyvsp[-1].string));}
#line 2104 "compiler_hw2.tab.c"
    break;

  case 101:
#line 481 "compiler_hw2.y"
           {(yyval.string)="PRINT";}
#line 2110 "compiler_hw2.tab.c"
    break;

  case 102:
#line 482 "compiler_hw2.y"
             {(yyval.string)="PRINTLN";}
#line 2116 "compiler_hw2.tab.c"
    break;


#line 2120 "compiler_hw2.tab.c"

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
#line 484 "compiler_hw2.y"

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
void pop_till_target(op_stack** top,char* target){
		while((*top)!=NULL&&(strcmp((*top)->op,target)&&precedence((*top)->op,1)<9)){	
			char* token=pop(top);
			printf("%s\n",token);
			free(token);
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
		while((*top)!=NULL&&strcmp((*top)->op,"[")){
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
