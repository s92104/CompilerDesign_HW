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
	enum varconstEnum
	{
		variable,constant
	};
	struct SymbolTableStruct
	{
		char name[100];
		char type[10];
		enum varconstEnum varconst;
		int intValue;
		char strValue[100];
	};
	struct SymbolTableStruct globalSymbolTable[100];
	struct SymbolTableStruct localSymbolTable[100];
	int globalSymbolCount=0;
	int localSymbolCount=0;
	int lookup(struct SymbolTableStruct symbolTable[],char compareString[],int symbolCount)
	{
		for(int i=0;i<symbolCount;i++)
		{
			if(!strcmp(symbolTable[i].name,compareString))
				return i;
		}
		return -1;
	}
	void dump(struct SymbolTableStruct symbolTable[],int symbolCount)	
	{
		for(int i=0;i<symbolCount;i++)
			printf("%d:%s:%s\n",lookup(symbolTable,symbolTable[i].name,symbolCount),symbolTable[i].name,symbolTable[i].type);
		printf("\n");
	}
	char* getSymbolType(char name[])
	{
		int index=lookup(localSymbolTable,name,localSymbolCount);
		if(index!=-1)
			return localSymbolTable[index].type;
		index=lookup(globalSymbolTable,name,globalSymbolCount);
		if(index!=-1)
			return globalSymbolTable[index].type;
		return strdup("null");
	}
	
	//ProcedureTable
	struct ProcedureTableStruct
	{
		char name[100];
		char type[10];
		char formalType[100][10];
		int formalTypeCount;
	};
	struct ProcedureTableStruct procedureTable[100];
	int procedureCount=0;
	int lookupProcedure(struct ProcedureTableStruct procedureTable[],char compareString[],int procedureCount)
	{
		for(int i=0;i<procedureCount;i++)
		{
			if(!strcmp(procedureTable[i].name,compareString))
				return i;
		}
		return -1;
	}
	void dumpProcedure( )	
	{
		for(int i=0;i<procedureCount;i++)
		{
			printf("%d:%s:%s\n",lookupProcedure(procedureTable,procedureTable[i].name,procedureCount),procedureTable[i].name,procedureTable[i].type);
			for(int j=0;j<procedureTable[i].formalTypeCount;j++)
				printf("%s ",procedureTable[i].formalType[j]);
			printf("\n");
		}
		printf("\n");
	}
	void addProcedure(char name[])
	{
		if(lookupProcedure(procedureTable,name,procedureCount)==-1)
		{
			procedureTable[procedureCount].name[0]='\0';
			strcat(procedureTable[procedureCount].name,name);
			procedureCount++;
		}
	}
	void checkProcedure(char name[])
	{
		if(lookupProcedure(procedureTable,name,procedureCount)==-1)
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
		if(lookup(localSymbolTable,name,localSymbolCount)==-1 && lookup(globalSymbolTable,name,globalSymbolCount)==-1 && lookupProcedure(procedureTable,name,procedureCount)==-1)
			printf("\"%s\" No Declaration:line%d\n",name,lineCount+1);
	}
	
	//DataType
	int typeCount=0;
	
	//Parameter Match
	int parameterCount=0;
	char callProcedureName[100];
	
	void addType(char type[],enum varconstEnum varconst)
	{
		if(scope==global)
		{
			for(int i=globalSymbolCount-typeCount;i<globalSymbolCount;i++)
			{
				sscanf(type,"%s",globalSymbolTable[i].type);
				globalSymbolTable[i].varconst=varconst;
				//Generate Code
				if(varconst==variable)
					printf("field static int %s\n",globalSymbolTable[i].name);
			}
		}
		else
		{
			for(int i=localSymbolCount-typeCount;i<localSymbolCount;i++)
			{
				sscanf(type,"%s",localSymbolTable[i].type);
				localSymbolTable[i].varconst=varconst;
			}
		}
		typeCount=0;
	}
	void addSymbol(char name[])	
	{
		if(!strcmp("",name))return;
		if(scope==global)
		{
			if(lookup(globalSymbolTable,name,globalSymbolCount)==-1)
			{
				sscanf(name,"%s",globalSymbolTable[globalSymbolCount].name);
				globalSymbolCount++;
			}
		}
		else
		{
			if(lookup(localSymbolTable,name,localSymbolCount)==-1)
			{
				sscanf(name,"%s",localSymbolTable[localSymbolCount].name);
				localSymbolCount++;
			}
		}	
	}
	//Constant Value
	int constInt;
	char constString[100];
	void addValue(int intValue,char strValue[])
	{
		if(scope==global)
		{
			globalSymbolTable[globalSymbolCount-1].intValue=intValue;
			strcpy(globalSymbolTable[globalSymbolCount-1].strValue,strValue);
		}
		else
		{
			localSymbolTable[localSymbolCount-1].intValue=intValue;
			strcpy(localSymbolTable[localSymbolCount-1].strValue,strValue);
		}	
	}
	
	//Label
	int labelCount=0;

#line 248 "y.tab.c" /* yacc.c:339  */

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
    XOR = 279,
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
#define XOR 279
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
#line 187 "CompilerProject2.y" /* yacc.c:355  */

	int integerVal;
	char stringVal[100];

#line 427 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 444 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
static const yytype_uint16 yyrline[] =
{
       0,   217,   217,   222,   227,   233,   215,   243,   244,   246,
     247,   248,   251,   252,   253,   255,   258,   259,   260,   262,
     265,   266,   268,   271,   272,   276,   276,   278,   276,   284,
     287,   286,   295,   298,   297,   306,   308,   309,   313,   314,
     317,   317,   322,   322,   329,   330,   331,   331,   332,   333,
     334,   339,   344,   349,   349,   355,   355,   358,   364,   372,
     380,   388,   396,   404,   405,   414,   464,   464,   465,   465,
     472,   481,   490,   499,   508,   517,   526,   534,   542,   551,
     561,   560,   570,   571,   572,   573,   576,   577,   578,   579,
     582,   583
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
  "NOTEQUAL", "AND", "OR", "XOR", "ASSIGNMENT", "ARRAY", "BOOLEAN",
  "BEGIN_", "BREAK", "CHAR", "CASE", "CONST", "CONTINUE", "DO", "ELSE",
  "END", "EXIT", "FOR", "FN", "IF", "IN", "INTEGER", "LOOP", "MODULE",
  "PRINT", "PRINTLN", "PROCEDURE", "REPEAT", "RETURN", "REAL", "STRING",
  "RECORD", "THEN", "TYPE", "USE", "UTIL", "VAR", "WHILE",
  "INTEGERCONSTANTS", "BOOLEANCONSTANTS", "REALCONSTANTS",
  "STRINGCONSTANTS", "IDENTIFIER", "PERIOD", "READ", "OF", "UMINUS",
  "$accept", "program", "$@1", "$@2", "$@3", "$@4",
  "variableconstant_decs", "variableconstant_dec", "constant_decs",
  "constant_dec", "variable_decs", "variable_dec", "array_decs",
  "array_dec", "identifiers", "function_decs", "$@5", "$@6", "$@7",
  "arguments", "$@8", "argument", "$@9", "proceduretype", "statements",
  "statement", "$@10", "$@11", "$@12", "$@13", "$@14", "expression",
  "$@15", "$@16", "commaseparated_expressions", "$@17", "constant",
  "datatype", "zero_statements", YY_NULLPTR
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

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -81

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,   -31,    37,  -116,  -116,   -27,   -25,   -23,    54,  -116,
     -27,  -116,   -23,    85,    38,  -116,    29,  -116,   -23,    94,
     -23,    55,  -116,  -116,    75,    24,     8,  -116,  -116,  -116,
    -116,   100,    49,  -116,    42,   101,   122,  -116,  -116,  -116,
    -116,   126,   -17,  -116,  -116,  -116,  -116,   127,  -116,  -116,
      74,  -116,  -116,   144,    32,   146,    89,   147,   164,     7,
       7,     2,   165,    88,    90,  -116,    32,   133,   113,   169,
      49,  -116,     7,     7,     7,    15,   123,  -116,   143,  -116,
     163,     7,   166,   181,   185,   186,  -116,  -116,   130,   200,
      49,  -116,   -27,   221,   239,   195,   205,   204,  -116,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,  -116,  -116,   257,     7,     7,  -116,     7,
     208,  -116,   182,  -116,   201,   177,  -116,     7,     7,    60,
      60,   195,   195,   303,    96,    96,    96,    96,    96,    96,
     331,   317,   345,   197,   183,   273,   103,   240,  -116,   202,
      49,   246,    32,    32,   258,   289,    32,  -116,   242,   280,
     294,  -116,   335,   290,   347,   332,    -9,  -116,  -116,   333,
       7,     7,  -116,  -116,   363,  -116,   307,    32,   366,   367,
     203,  -116,    49,  -116,   337,  -116,  -116,  -116,  -116,   369,
     370,   246,    55,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     8,     0,     0,    24,     3,
       8,    11,    21,     0,     0,     9,    14,    10,    18,     0,
       0,    29,     7,    20,     0,     0,    24,    12,    13,    16,
      17,     0,     0,    23,     0,     0,     0,    83,    84,    85,
      82,     0,     0,    89,    87,    88,    86,     0,    25,     4,
       0,    15,    19,    32,    91,     0,     0,    37,     0,     0,
       0,     0,     0,    40,     0,    90,    38,     0,     0,     0,
       0,    26,     0,     0,     0,    65,     0,    64,     0,    48,
       0,     0,     0,     0,     0,     0,    46,    39,     0,     0,
       0,    36,     8,     0,     0,    57,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    49,     0,     0,     0,    54,     0,
       0,     5,     0,    30,     0,     0,    63,     0,     0,    60,
      61,    58,    59,    62,    70,    71,    73,    74,    72,    75,
      77,    78,    76,     0,     0,     0,    79,     0,    47,     0,
       0,    35,     0,    91,     0,     0,    91,    41,     0,     0,
       0,     6,     0,     0,     0,     0,     0,    67,    69,     0,
       0,     0,    56,    22,     0,    31,     0,    91,     0,     0,
       0,    81,     0,    27,     0,    51,    52,    43,    33,     0,
       0,    35,    29,    50,    34,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,  -116,  -116,    -4,  -116,   360,  -116,
     359,  -116,    23,  -116,    11,   187,  -116,  -116,  -116,  -116,
    -116,   189,  -116,  -116,   -65,  -116,  -116,  -116,  -116,  -116,
    -116,   -57,  -116,  -116,  -115,  -116,   353,   -70,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    21,    54,   149,     9,    10,    15,    16,
      17,    18,    11,    12,    13,    35,    53,    92,   189,    57,
     151,   164,   191,    71,    65,    66,    82,    83,   120,    84,
      85,   146,    96,    97,   147,   159,    77,    47,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    87,    76,    78,    80,     6,    22,    79,    73,    36,
      43,    20,   154,    73,    74,    93,    94,    95,    19,    74,
     123,   -66,     1,   -68,   115,    44,   177,   178,    25,    31,
       7,    33,     3,    45,    46,    23,     8,     4,    14,    28,
       8,    30,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   181,    20,    25,   144,
     145,    37,    38,    39,    40,    75,    37,    38,    39,    40,
      75,   155,    58,   101,   102,   103,    43,    59,    60,   166,
     162,    61,   169,    37,    38,    39,    40,   165,   124,    24,
      62,    44,    26,   -53,   -55,    63,   -42,    64,    32,    45,
      46,    36,    34,   184,    42,    48,   -80,    99,   100,   101,
     102,   103,   188,   180,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    98,    49,
      50,    51,    52,    55,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    68,
      56,    70,    69,    86,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   114,    88,
      72,    81,    89,    90,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   157,   117,
     118,   116,   119,   121,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   187,   122,
     103,   127,   128,   148,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   125,   152,
     153,   156,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   126,   160,   150,   163,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   143,   167,   161,   170,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   158,   171,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   168,   172,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     173,   112,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   174,   175,   112,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   182,   176,   179,
     183,   185,   186,   190,   192,   193,    27,    29,    41,   195,
     194
};

static const yytype_uint8 yycheck[] =
{
      70,    66,    59,    60,    61,    32,    10,     5,     6,    26,
      27,     3,   127,     6,    12,    72,    73,    74,     7,    12,
      90,     6,    44,     8,    81,    42,    35,    36,    20,    18,
      57,    20,    63,    50,    51,    12,    63,     0,    63,    16,
      63,    18,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   171,     3,    20,   116,
     117,    59,    60,    61,    62,    63,    59,    60,    61,    62,
      63,   128,    40,    13,    14,    15,    27,    45,    46,   153,
     150,    49,   156,    59,    60,    61,    62,   152,    92,     4,
      58,    42,    63,     5,     6,    63,     8,    65,     4,    50,
      51,    26,    47,   177,     4,    63,     3,    11,    12,    13,
      14,    15,   182,   170,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    28,
       8,     5,     5,    59,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,     3,
       6,     4,    63,    63,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,    36,
       6,     6,    59,     4,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,     8,
       5,    25,     6,    63,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     5,     9,
      15,     6,     8,     5,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,    28,
      53,    34,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,     7,    66,     3,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     7,     7,    64,    25,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     9,     3,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     9,     5,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       5,    24,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    63,     7,    24,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     4,    36,    36,
      63,     5,     5,    36,     5,     5,    16,    18,    25,   192,
     191
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    69,    63,     0,    70,    32,    57,    63,    74,
      75,    80,    81,    82,    63,    76,    77,    78,    79,    82,
       3,    71,    74,    80,     4,    20,    63,    76,    80,    78,
      80,    82,     4,    82,    47,    83,    26,    59,    60,    61,
      62,   104,     4,    27,    42,    50,    51,   105,    63,    28,
       8,     5,     5,    84,    72,    59,     6,    87,    40,    45,
      46,    49,    58,    63,    65,    92,    93,   106,     3,    63,
       4,    91,     6,     6,    12,    63,    99,   104,    99,     5,
      99,     6,    94,    95,    97,    98,    63,    92,    36,    59,
       4,   105,    85,    99,    99,    99,   100,   101,     5,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     5,     5,    99,    25,     8,     5,     6,
      96,    63,     9,   105,    74,     7,     7,     6,     8,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,     7,    99,    99,    99,   102,     5,    73,
      66,    88,    28,    53,   102,    99,    34,     5,     9,   103,
       7,    64,   105,     3,    89,    92,   106,     7,     9,   106,
      25,     3,     5,     5,    63,     7,    36,    35,    36,    36,
      99,   102,     4,    63,   106,     5,     5,     5,   105,    86,
      36,    90,     5,     5,    89,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    70,    71,    72,    73,    69,    74,    74,    75,
      75,    75,    76,    76,    76,    77,    78,    78,    78,    79,
      80,    80,    81,    82,    82,    84,    85,    86,    83,    83,
      88,    87,    87,    90,    89,    89,    91,    91,    92,    92,
      94,    93,    95,    93,    93,    93,    96,    93,    93,    93,
      93,    93,    93,    97,    93,    98,    93,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,    99,   101,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   102,
     103,   102,   104,   104,   104,   104,   105,   105,   105,   105,
     106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    13,     2,     0,     2,
       2,     1,     2,     2,     1,     4,     2,     2,     1,     4,
       2,     1,    11,     3,     1,     0,     0,     0,    14,     0,
       0,     7,     0,     0,     6,     0,     2,     0,     1,     2,
       0,     5,     0,     8,     3,     3,     0,     4,     2,     3,
      10,     8,     8,     0,     3,     0,     6,     2,     3,     3,
       3,     3,     3,     3,     1,     1,     0,     5,     0,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 217 "CompilerProject2.y" /* yacc.c:1646  */
    {
	//Generate Code
	printf("class a\n{\n");
}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 222 "CompilerProject2.y" /* yacc.c:1646  */
    {
	scope=local;
}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 227 "CompilerProject2.y" /* yacc.c:1646  */
    {
	//Generate Code
	printf("method public static void main(java.lang.String[])\nmax_stack 15\nmax_locals 15\n{\n");
}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 233 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-9].stringVal),(yyvsp[0].stringVal)))
		printf("Wrong Program Name:line%d\n",lineCount+1);
	//Generate Code
	printf("return\n}\n}");
}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 255 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-3].stringVal));typeCount++;addType((yyvsp[-1].stringVal),constant);addValue(constInt,constString);}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 262 "CompilerProject2.y" /* yacc.c:1646  */
    {addType((yyvsp[-1].stringVal),variable);}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 268 "CompilerProject2.y" /* yacc.c:1646  */
    {addType((yyvsp[-1].stringVal),variable);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 271 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[-2].stringVal));typeCount++;}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "CompilerProject2.y" /* yacc.c:1646  */
    {addSymbol((yyvsp[0].stringVal));typeCount++;}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 276 "CompilerProject2.y" /* yacc.c:1646  */
    {addProcedure((yyvsp[0].stringVal));}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 276 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",procedureTable[procedureCount-1].type);}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 278 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-9].stringVal),(yyvsp[0].stringVal)))
		printf("Wrong Procedure Name:line%d\n",lineCount+1);
	localSymbolCount=0;
}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 287 "CompilerProject2.y" /* yacc.c:1646  */
    {
	addSymbol((yyvsp[-2].stringVal));
	typeCount++;
	addType((yyvsp[0].stringVal),variable);
	sscanf((yyvsp[0].stringVal),"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 298 "CompilerProject2.y" /* yacc.c:1646  */
    {
	addSymbol((yyvsp[-2].stringVal));
	typeCount++;
	addType((yyvsp[0].stringVal),variable);
	sscanf((yyvsp[0].stringVal),"%s",procedureTable[procedureCount-1].formalType[procedureTable[procedureCount-1].formalTypeCount]);
	procedureTable[procedureCount-1].formalTypeCount++;
}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 308 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 309 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf("void","%s",(yyval.stringVal));}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 317 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 318 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp(getSymbolType((yyvsp[-4].stringVal)),(yyvsp[-1].stringVal)))
			printf("Assignment Not Consistent:line%d\n",lineCount+1);
}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 322 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 323 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp(getSymbolType((yyvsp[-7].stringVal)),(yyvsp[-1].stringVal)))
		printf("Assignment Not Consistent:line%d\n",lineCount+1);
	if(strcmp((yyvsp[-4].stringVal),"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 331 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 335 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-7].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 340 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-5].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 345 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-5].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 349 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 350 "CompilerProject2.y" /* yacc.c:1646  */
    {
	int index=lookupProcedure(procedureTable,(yyvsp[-2].stringVal),procedureCount);
	if(procedureTable[index].formalTypeCount!=0)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 355 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));sscanf((yyvsp[0].stringVal),"%s",callProcedureName);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 359 "CompilerProject2.y" /* yacc.c:1646  */
    {
	sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("ineg\n");
}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 365 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[-2].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("imul\n");
}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 373 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[-2].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("idiv\n");
}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 381 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[-2].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("iadd\n");
}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 389 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[-2].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("isub\n");
}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 397 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf((yyvsp[-2].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	printf("irem\n");
}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 404 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[-1].stringVal),"%s",(yyval.stringVal));}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 406 "CompilerProject2.y" /* yacc.c:1646  */
    {
	sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));
	//Generate Code
	if(strcmp((yyvsp[0].stringVal),"string"))
		printf("sipush %d\n",constInt);
	else
		printf("ldc \"%s\"\n",constString);
}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 415 "CompilerProject2.y" /* yacc.c:1646  */
    {
	checkall((yyvsp[0].stringVal));
	char* type=getSymbolType((yyvsp[0].stringVal));
	if(strcmp(type,"null"))
	{
		sscanf(type,"%s",(yyval.stringVal));
		//Generate Code
		int index=lookup(globalSymbolTable,(yyvsp[0].stringVal),globalSymbolCount);
		//Global
		if(index!=-1)
		{
			//Variable
			if(globalSymbolTable[index].varconst==variable)
				printf("getstatic int a.%s\n",(yyvsp[0].stringVal));
			//Constant
			else
			{
				if(strcmp(type,"string"))
					printf("sipush %d\n",globalSymbolTable[index].intValue);
				else
					printf("ldc \"%s\"\n",globalSymbolTable[index].strValue);
			}			
		}
		//Local
		else
		{
			index=lookup(localSymbolTable,(yyvsp[0].stringVal),localSymbolCount);
			if(localSymbolTable[index].varconst==variable)
				printf("iload %d\n",index);
			else
			{
				if(strcmp(type,"string"))
					printf("sipush %d\n",localSymbolTable[index].intValue);
				else
					printf("ldc \"%s\"\n",localSymbolTable[index].strValue);
			}
		}
	}
	else
	{
		int index=lookupProcedure(procedureTable,(yyvsp[0].stringVal),procedureCount);
		if(index!=-1)
		{
			if(procedureTable[index].formalTypeCount!=0)
				printf("Parameter Type Not Match:line%d\n",lineCount+1);
			sscanf(procedureTable[index].type,"%s",(yyval.stringVal));
		}
	}	
}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 464 "CompilerProject2.y" /* yacc.c:1646  */
    {checkProcedure((yyvsp[0].stringVal));sscanf((yyvsp[0].stringVal),"%s",callProcedureName);}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 464 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf(procedureTable[lookupProcedure(procedureTable,(yyvsp[-4].stringVal),procedureCount)].type,"%s",(yyval.stringVal));}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 465 "CompilerProject2.y" /* yacc.c:1646  */
    {checkScope((yyvsp[0].stringVal));}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 466 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-1].stringVal),"integer"))
		printf("Only Integer:line%d\n",lineCount+1);
	sscanf(getSymbolType((yyvsp[-4].stringVal)),"%s",(yyval.stringVal));
}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 473 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\niflt L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 482 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\nifle L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 491 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\nifeq L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 500 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\nifge L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 509 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\nifgt L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 518 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),(yyvsp[0].stringVal)))
		printf("Expression Not Consistent:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("isub\nifne L%d\niconst_0\ngoto L%d\nL%d:iconst_1\nL%d:\n",labelCount,labelCount+1,labelCount,labelCount+1);
	labelCount+=2;
}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 527 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),"boolean")||strcmp((yyvsp[0].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("ixor\n");
}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 535 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),"boolean")||strcmp((yyvsp[0].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("iand\n");
}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 543 "CompilerProject2.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-2].stringVal),"boolean")||strcmp((yyvsp[0].stringVal),"boolean"))
		printf("Only Boolean:line%d\n",lineCount+1);
	sscanf("boolean","%s",(yyval.stringVal));
	//Generate Code
	printf("ior\n");
}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 552 "CompilerProject2.y" /* yacc.c:1646  */
    {
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp((yyvsp[0].stringVal),procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	else if(parameterCount+1!=procedureTable[index].formalTypeCount)
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount=0;
}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 561 "CompilerProject2.y" /* yacc.c:1646  */
    {
	int index=lookupProcedure(procedureTable,callProcedureName,procedureCount);
	if(strcmp((yyvsp[0].stringVal),procedureTable[index].formalType[parameterCount]))
		printf("Parameter Type Not Match:line%d\n",lineCount+1);
	parameterCount++;
}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 570 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf("string","%s",(yyval.stringVal));strcpy(constString,(yyvsp[0].stringVal));}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 571 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf("integer","%s",(yyval.stringVal));constInt=(yyvsp[0].integerVal);}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 572 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf("boolean","%s",(yyval.stringVal));constInt=(yyvsp[0].integerVal);}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 573 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf("real","%s",(yyval.stringVal));}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 576 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 577 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 578 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 579 "CompilerProject2.y" /* yacc.c:1646  */
    {sscanf((yyvsp[0].stringVal),"%s",(yyval.stringVal));}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2272 "y.tab.c" /* yacc.c:1646  */
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
#line 585 "CompilerProject2.y" /* yacc.c:1906  */

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
