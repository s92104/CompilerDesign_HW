/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 91 "CompilerProject2.y" /* yacc.c:1909  */

	int integerVal;
	char stringVal[100];

#line 193 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
