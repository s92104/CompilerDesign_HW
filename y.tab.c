/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "CompilerProject2.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>	

	extern int lineCount;
	
	//SymbolTable
	enum symbolType
	{
		string,integer,boolean,real
	};
	struct SymbolTableStruct
	{
		char name[100];
		enum symbolType type;
	};
	struct SymbolTableStruct globalSymbolTable[100];
	struct SymbolTableStruct localSymbolTable[100];
	int globalSymbolCount=0;
	int localSymbolCount=0;
	
	//ProcedureTable
	struct ProcedureTableStruct
	{
		char name[100];
		enum symbolType type;
	};
	struct ProcedureTableStruct procedureTable[100];
	int procedureCount=0;
	void addProcedure(char name[])
	{
		if(lookup(procedureTable,name,procedureCount)==-1)
		{
			procedureTable[procedureCount].name[0]='\0';
			strcat(procedureTable[procedureCount].name,name);
			procedureCount++;
		}
	}
	void checkProcedure(char name[])
	{
		if(lookup(procedureTable,name,procedureCount)==-1)
			printf("\"%s\" No Function Declaration:line%d\n",name,lineCount+1);
	}
	
	//Scope
	enum scopeEnum
	{
		global,local
	};
	enum scopeEnum scope=global;
	void checkScope(char name[])
	{
		if(lookup(localSymbolTable,name,localSymbolCount)==-1 && lookup(globalSymbolTable,name,globalSymbolCount)==-1)
			printf("\"%s\" No Declaration:line%d\n",name,lineCount+1);
	}
	
	void checkall(char name[])
	{
		if(lookup(localSymbolTable,name,localSymbolCount)==-1 && lookup(globalSymbolTable,name,globalSymbolCount)==-1 && lookup(procedureTable,name,procedureCount)==-1)
			printf("\"%s\" No Declaration:line%d\n",name,lineCount+1);
	}
	
	void addSymbol(char name[])	
	{
		if(scope==global)
		{
			if(lookup(globalSymbolTable,name,globalSymbolCount)==-1)
			{
				globalSymbolTable[globalSymbolCount].name[0]='\0';
				strcat(globalSymbolTable[globalSymbolCount].name,name);
				globalSymbolCount++;
			}
		}
		else
		{
			if(lookup(localSymbolTable,name,localSymbolCount)==-1)
			{
				localSymbolTable[localSymbolCount].name[0]='\0';
				strcat(localSymbolTable[localSymbolCount].name,name);
				localSymbolCount++;
			}
		}
			
	}

#line 152 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    COMMA = 258,
    COLON = 259,
    SEMICOLON = 260,
    LEFTPARENTHESES = 261,
    RIGHTPARENTHESES = 262,
    LEFTSQUAREBRACKETS = 263,
    RIGHTSQUAREBRACKETS = 264,
    BRACKETS = 265,
    PLUS = 266,
    MINUS = 267,
    MULTIPLY = 268,
    DIVIDE = 269,
    REMAINDER = 270,
    LESS = 271,
    LESSEQUAL = 272,
    GREATEREQUAL = 273,
    GREATER = 274,
    EQUAL = 275,
    NOTEQUAL = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    ASSIGNMENT = 280,
    ARRAY = 281,
    BOOLEAN = 282,
    BEGIN_ = 283,
    BREAK = 284,
    CHAR = 285,
    CASE = 286,
    CONST = 287,
    CONTINUE = 288,
    DO = 289,
    ELSE = 290,
    END = 291,
    EXIT = 292,
    FOR = 293,
    FN = 294,
    IF = 295,
    IN = 296,
    INTEGER = 297,
    LOOP = 298,
    MODULE = 299,
    PRINT = 300,
    PRINTLN = 301,
    PROCEDURE = 302,
    REPEAT = 303,
    RETURN = 304,
    REAL = 305,
    STRING = 306,
    RECORD = 307,
    THEN = 308,
    TYPE = 309,
    USE = 310,
    UTIL = 311,
    VAR = 312,
    WHILE = 313,
    INTEGERCONSTANTS = 314,
    BOOLEANCONSTANTS = 315,
    REALCONSTANTS = 316,
    STRINGCONSTANTS = 317,
    IDENTIFIER = 318,
    PERIOD = 319,
    READ = 320,
    OF = 321,
    UMINUS = 322
  };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define SEMICOLON 260
#define LEFTPARENTHESES 261
#define RIGHTPARENTHESES 262
#define LEFTSQUAREBRACKETS 263
#define RIGHTSQUAREBRACKETS 264
#define BRACKETS 265
#define PLUS 266
#define MINUS 267
#define MULTIPLY 268
#define DIVIDE 269
#define REMAINDER 270
#define LESS 271
#define LESSEQUAL 272
#define GREATEREQUAL 273
#define GREATER 274
#define EQUAL 275
#define NOTEQUAL 276
#define AND 277
#define OR 278
#define NOT 279
#define ASSIGNMENT 280
#define ARRAY 281
#define BOOLEAN 282
#define BEGIN_ 283
#define BREAK 284
#define CHAR 285
#define CASE 286
#define CONST 287
#define CONTINUE 288
#define DO 289
#define ELSE 290
#define END 291
#define EXIT 292
#define FOR 293
#define FN 294
#define IF 295
#define IN 296
#define INTEGER 297
#define LOOP 298
#define MODULE 299
#define PRINT 300
#define PRINTLN 301
#define PROCEDURE 302
#define REPEAT 303
#define RETURN 304
#define REAL 305
#define STRING 306
#define RECORD 307
#define THEN 308
#define TYPE 309
#define USE 310
#define UTIL 311
#define VAR 312
#define WHILE 313
#define INTEGERCONSTANTS 314
#define BOOLEANCONSTANTS 315
#define REALCONSTANTS 316
#define STRINGCONSTANTS 317
#define IDENTIFIER 318
#define PERIOD 319
#define READ 320
#define OF 321
#define UMINUS 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 91 "CompilerProject2.y" /* yacc.c:355  */

	int integerVal;
	char stringVal[100];

#line 331 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 348 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   115,   108,   123,   124,   126,   127,   128,
     131,   132,   133,   135,   138,   139,   140,   142,   146,   147,
     149,   153,   155,   153,   161,   163,   164,   166,   167,   169,
     170,   174,   175,   178,   178,   179,   179,   180,   181,   182,
     182,   183,   184,   185,   186,   187,   188,   188,   189,   189,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   200,
     201,   201,   203,   204,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   215,   216,   216,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     236,   237,   238,   239,   242,   243,   244,   245,   248,   249,
     252,   253
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "SEMICOLON",
  "LEFTPARENTHESES", "RIGHTPARENTHESES", "LEFTSQUAREBRACKETS",
  "RIGHTSQUAREBRACKETS", "BRACKETS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "REMAINDER", "LESS", "LESSEQUAL", "GREATEREQUAL", "GREATER", "EQUAL",
  "NOTEQUAL", "AND", "OR", "NOT", "ASSIGNMENT", "ARRAY", "BOOLEAN",
  "BEGIN_", "BREAK", "CHAR", "CASE", "CONST", "CONTINUE", "DO", "ELSE",
  "END", "EXIT", "FOR", "FN", "IF", "IN", "INTEGER", "LOOP", "MODULE",
  "PRINT", "PRINTLN", "PROCEDURE", "REPEAT", "RETURN", "REAL", "STRING",
  "RECORD", "THEN", "TYPE", "USE", "UTIL", "VAR", "WHILE",
  "INTEGERCONSTANTS", "BOOLEANCONSTANTS", "REALCONSTANTS",
  "STRINGCONSTANTS", "IDENTIFIER", "PERIOD", "READ", "OF", "UMINUS",
  "$accept", "program", "$@1", "$@2", "variableconstant_decs",
  "variableconstant_dec", "constant_decs", "constant_dec", "variable_decs",
  "variable_dec", "array_decs", "array_dec", "function_decs", "$@3", "$@4",
  "arguments", "argument", "proceduretype", "statements", "statement",
  "$@5", "$@6", "$@7", "$@8", "$@9", "expression", "$@10", "$@11",
  "commaseparated_expressions", "integer_expression", "$@12", "$@13",
  "boolean_expression", "constant", "datatype", "identifiers",
  "zero_statements", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -88

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -51,    16,   -21,  -141,   -42,   -34,    45,  -141,   -21,
    -141,   -34,    49,    37,  -141,    15,  -141,   -34,    89,   -34,
      54,  -141,  -141,    94,   194,     7,  -141,  -141,  -141,  -141,
     110,    88,  -141,    59,   118,   139,  -141,  -141,  -141,  -141,
     147,    57,  -141,  -141,  -141,  -141,   149,  -141,    78,   128,
    -141,  -141,   171,   195,    43,    43,    26,   207,    67,   105,
    -141,    78,   153,   196,   140,   210,    50,    43,    43,     9,
     137,  -141,   179,  -141,   183,    50,   175,   214,   216,   209,
    -141,  -141,   160,   170,   243,    88,   -21,    50,    50,     0,
     111,   162,   109,   205,  -141,   229,   233,  -141,    43,    43,
      43,    43,  -141,  -141,   122,    43,    31,  -141,    43,   247,
    -141,   252,    88,  -141,   234,   146,   133,  -141,    43,    31,
      43,    43,    43,    43,    43,    43,   211,    50,    50,  -141,
      43,    31,    21,    21,  -141,  -141,   232,   193,    31,    31,
    -141,    92,   219,   158,   256,  -141,   201,   202,   264,    78,
    -141,   262,   225,   246,   246,   246,   246,   246,   246,    78,
    -141,   248,   265,   231,    78,  -141,   213,  -141,   267,   263,
     249,    31,    31,    31,    31,    43,   270,  -141,    88,   215,
     269,   241,   274,  -141,    90,  -141,  -141,   244,  -141,    43,
      31,    43,   172,   172,  -141,  -141,  -141,  -141,   276,   278,
    -141,   220,  -141,    78,   279,   280,   281,   237,   197,  -141,
      88,  -141,   250,  -141,  -141,   282,  -141,  -141,   264,   284,
     285,  -141,  -141,    54,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     1,     0,     0,    99,     2,     6,
       9,    19,     0,     0,     7,    12,     8,    16,     0,     0,
      24,     5,    18,     0,     0,    99,    10,    11,    14,    15,
       0,     0,    98,     0,     0,     0,    91,    92,    93,    90,
       0,     0,    97,    95,    96,    94,     0,    21,   101,     0,
      13,    17,    26,     0,     0,     0,     0,     0,    33,     0,
     100,    31,     0,     0,     0,    30,     0,     0,     0,    57,
       0,    56,     0,    41,     0,     0,     0,     0,     0,     0,
      39,    32,     0,     0,     0,     0,     6,     0,     0,    92,
      57,     0,     0,     0,    50,     0,     0,    37,     0,     0,
       0,     0,    38,    42,     0,     0,     0,    47,     0,     0,
       3,     0,     0,    29,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    53,    54,    51,    52,     0,     0,     0,     0,
      70,    71,     0,    62,     0,    40,     0,     0,    28,     0,
      85,     0,     0,    76,    77,    79,    80,    78,    81,   101,
      83,    84,     0,     0,   101,    34,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,    89,     0,    59,    61,     0,    69,     0,
       0,     0,    67,    68,    65,    66,    63,    49,     0,     0,
      25,     0,    88,   101,     0,     0,     0,     0,     0,    20,
       0,    22,     0,    44,    45,     0,    75,    36,    28,     0,
       0,    73,    27,    24,    43,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,    -4,  -141,   277,  -141,   283,  -141,
      80,  -141,    68,  -141,  -141,  -141,    75,  -141,   -57,  -141,
    -141,  -141,  -141,  -141,  -141,   -54,  -141,  -141,  -110,  -113,
    -141,  -141,   -47,   271,   -82,    33,  -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    20,   146,     8,     9,    14,    15,    16,    17,
      10,    11,    34,    52,   219,    65,   180,    86,    60,    61,
      76,    77,   109,    78,    79,    91,    95,    96,   144,   142,
     168,   169,    92,    71,    46,    12,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    72,    74,   113,    81,    21,   152,   -86,   151,     1,
      19,     5,     3,    93,    94,   -58,     4,   -60,   163,   184,
     162,    13,   -86,   -86,   187,   166,   167,    24,   104,     7,
     148,    73,    67,   115,   100,   101,     6,   138,    68,    18,
     116,   117,     7,   139,   132,   133,   134,   135,    19,    67,
      30,   137,    32,    23,   143,    68,    87,    24,   192,   193,
     194,   195,    68,   212,   143,   196,   153,   154,   155,   156,
     157,   158,   -46,   -48,    88,   -35,   143,   207,    25,   206,
     160,   161,   114,    35,    42,    36,    37,    38,    39,    69,
     140,    22,   181,    31,   141,    27,   198,    29,   -72,    43,
     -74,    33,    36,    37,    38,    39,    69,    44,    45,    36,
      89,    38,    39,    90,    41,    42,   126,   118,    53,   119,
      35,   143,    47,    54,    55,   203,   204,    56,   218,   136,
      43,   127,   128,   -87,   -87,   143,    57,   208,    44,    45,
     150,    58,    97,    59,   127,   128,    48,    49,    98,    99,
     100,   101,    50,   129,    51,   127,   128,    98,    99,   100,
     101,   175,   120,   121,   122,   123,   124,   125,    80,    98,
      99,   100,   101,    98,    99,   100,   101,    64,   120,   121,
     122,   123,   124,   125,   102,   173,   174,    63,   103,    82,
      98,    99,   100,   101,    98,    99,   100,   101,   165,    83,
     105,    66,   217,    84,    98,    99,   100,   101,    98,    99,
     100,   101,   129,    75,    85,   108,    98,    99,   100,   101,
     188,   107,   106,   110,   171,   172,   173,   174,   170,   111,
     171,   172,   173,   174,   183,   130,   171,   172,   173,   174,
     186,   131,   171,   172,   173,   174,   216,   112,   171,   172,
     173,   174,   145,    36,    37,    38,    39,    98,    99,   100,
     101,   147,   149,   176,   159,   177,   164,   179,   178,   182,
     127,   190,   185,   189,   191,   197,   200,   201,   199,   202,
     205,   209,   210,   211,   213,   214,   220,   221,   215,   223,
     224,   225,    26,   222,     0,    40,     0,     0,     0,     0,
      28
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,    85,    61,     9,   119,     7,   118,    44,
       3,    32,    63,    67,    68,     6,     0,     8,   131,   159,
     130,    63,    22,    23,   164,   138,   139,    20,    75,    63,
     112,     5,     6,    87,    13,    14,    57,     6,    12,     6,
      87,    88,    63,    12,    98,    99,   100,   101,     3,     6,
      17,   105,    19,     4,   108,    12,     6,    20,   171,   172,
     173,   174,    12,   203,   118,   175,   120,   121,   122,   123,
     124,   125,     5,     6,    24,     8,   130,   190,    63,   189,
     127,   128,    86,    26,    27,    59,    60,    61,    62,    63,
      59,    11,   149,     4,    63,    15,   178,    17,     6,    42,
       8,    47,    59,    60,    61,    62,    63,    50,    51,    59,
      60,    61,    62,    63,     4,    27,     7,     6,    40,     8,
      26,   175,    63,    45,    46,    35,    36,    49,   210,     7,
      42,    22,    23,    22,    23,   189,    58,   191,    50,    51,
       7,    63,     5,    65,    22,    23,    28,     8,    11,    12,
      13,    14,     5,     7,     5,    22,    23,    11,    12,    13,
      14,     3,    16,    17,    18,    19,    20,    21,    63,    11,
      12,    13,    14,    11,    12,    13,    14,     6,    16,    17,
      18,    19,    20,    21,     5,    13,    14,    59,     5,    36,
      11,    12,    13,    14,    11,    12,    13,    14,     5,     3,
      25,     6,     5,    63,    11,    12,    13,    14,    11,    12,
      13,    14,     7,     6,     4,     6,    11,    12,    13,    14,
       7,     5,     8,    63,    11,    12,    13,    14,     9,    59,
      11,    12,    13,    14,     9,     6,    11,    12,    13,    14,
       9,     8,    11,    12,    13,    14,     9,     4,    11,    12,
      13,    14,     5,    59,    60,    61,    62,    11,    12,    13,
      14,     9,    28,     7,    53,    64,    34,     3,    66,     7,
      22,     8,     7,     6,    25,     5,     7,    36,    63,     5,
      36,     5,     4,    63,     5,     5,    36,     5,     7,     5,
       5,   223,    15,   218,    -1,    24,    -1,    -1,    -1,    -1,
      17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    69,    63,     0,    32,    57,    63,    72,    73,
      78,    79,   103,    63,    74,    75,    76,    77,   103,     3,
      70,    72,    78,     4,    20,    63,    74,    78,    76,    78,
     103,     4,   103,    47,    80,    26,    59,    60,    61,    62,
     101,     4,    27,    42,    50,    51,   102,    63,    28,     8,
       5,     5,    81,    40,    45,    46,    49,    58,    63,    65,
      86,    87,   104,    59,     6,    83,     6,     6,    12,    63,
      93,   101,    93,     5,    93,     6,    88,    89,    91,    92,
      63,    86,    36,     3,    63,     4,    85,     6,    24,    60,
      63,    93,   100,    93,    93,    94,    95,     5,    11,    12,
      13,    14,     5,     5,   100,    25,     8,     5,     6,    90,
      63,    59,     4,   102,    72,    93,   100,   100,     6,     8,
      16,    17,    18,    19,    20,    21,     7,    22,    23,     7,
       6,     8,    93,    93,    93,    93,     7,    93,     6,    12,
      59,    63,    97,    93,    96,     5,    71,     9,   102,    28,
       7,    96,    97,    93,    93,    93,    93,    93,    93,    53,
     100,   100,    96,    97,    34,     5,    97,    97,    98,    99,
       9,    11,    12,    13,    14,     3,     7,    64,    66,     3,
      84,    86,     7,     9,   104,     7,     9,   104,     7,     6,
       8,    25,    97,    97,    97,    97,    96,     5,   102,    63,
       7,    36,     5,    35,    36,    36,    96,    97,    93,     5,
       4,    63,   104,     5,     5,     7,     9,     5,   102,    82,
      36,     5,    84,     5,     5,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    70,    71,    69,    72,    72,    73,    73,    73,
      74,    74,    74,    75,    76,    76,    76,    77,    78,    78,
      79,    81,    82,    80,    80,    83,    83,    84,    84,    85,
      85,    86,    86,    88,    87,    89,    87,    87,    87,    90,
      87,    87,    87,    87,    87,    87,    91,    87,    92,    87,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    93,
      95,    93,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    97,    99,    97,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    11,     2,     0,     2,     2,     1,
       2,     2,     1,     4,     2,     2,     1,     4,     2,     1,
      11,     0,     0,    13,     0,     6,     0,     5,     0,     2,
       0,     1,     2,     0,     5,     0,     8,     3,     3,     0,
       4,     2,     3,    10,     8,     8,     0,     3,     0,     6,
       2,     3,     3,     3,     3,     3,     1,     1,     0,     5,
       0,     5,     1,     3,     2,     3,     3,     3,     3,     3,
       1,     1,     0,     6,     0,     5,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     1,     1,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 110 "CompilerProject2.y" /* yacc.c:1646  */
    {
	scope=local;
}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-7].stringVal),(yyvsp[0].stringVal)))
		printf("Wrong Program Name:line%d\n",lineCount+1);
}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-3].stringVal));}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "CompilerProject2.y" /* yacc.c:1646  */
    {addProcedure((yyvsp[0].stringVal));}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 155 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-8].stringVal),(yyvsp[0].stringVal)))
		printf("Wrong Procedure Name:line%d\n",lineCount+1);
	localSymbolCount=0;
}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-4].stringVal));}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 166 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-3].stringVal));}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 182 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 188 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 189 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 199 "CompilerProject2.y" /* yacc.c:1646  */
    {checkall((yyvsp[0].stringVal));}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 200 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 201 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "CompilerProject2.y" /* yacc.c:1646  */
    {checkall((yyvsp[0].stringVal));}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 215 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 216 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 230 "CompilerProject2.y" /* yacc.c:1646  */
    {checkall((yyvsp[0].stringVal));}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 231 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[-4].stringVal));}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[-3].stringVal));}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 248 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-2].stringVal));}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 249 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[0].stringVal));}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1750 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 255 "CompilerProject2.y" /* yacc.c:1906  */


int yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
	return 0;
}
int main(void)
{
	yyparse();
	return 0;
}
