%{
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
%}


%token COMMA COLON SEMICOLON LEFTPARENTHESES RIGHTPARENTHESES LEFTSQUAREBRACKETS RIGHTSQUAREBRACKETS BRACKETS PLUS MINUS MULTIPLY DIVIDE REMAINDER LESS LESSEQUAL GREATEREQUAL GREATER EQUAL NOTEQUAL AND OR NOT ASSIGNMENT ARRAY BOOLEAN BEGIN_ BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FOR FN IF IN INTEGER LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TYPE USE UTIL VAR WHILE INTEGERCONSTANTS BOOLEANCONSTANTS REALCONSTANTS STRINGCONSTANTS IDENTIFIER PERIOD READ OF

%union
{
	int integerVal;
	char stringVal[100];
}
%type <stringVal> IDENTIFIER

%left OR
%left AND
%left NOT
%left LESS LESSEQUAL EQUAL GREATEREQUAL GREATER NOTEQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%nonassoc UMINUS

%%

//Program
program:MODULE IDENTIFIER 
variableconstant_decs
{
	scope=local;
} 
function_decs BEGIN_ zero_statements END 
IDENTIFIER
{
	if(strcmp($2,$9))
		printf("Wrong Program Name:line%d\n",lineCount+1);
} 
PERIOD
;

//Declarations
variableconstant_decs:variableconstant_dec variableconstant_decs
|
;
variableconstant_dec:CONST constant_decs
|VAR variable_decs	
|array_decs	
;
//Constants
constant_decs:constant_dec constant_decs
|constant_dec array_decs	
|constant_dec	
;
constant_dec:IDENTIFIER EQUAL constant SEMICOLON	{addSymbol($1);}	
;
//Variables
variable_decs:variable_dec variable_decs
|variable_dec array_decs	
|variable_dec	
;
variable_dec:identifiers COLON datatype SEMICOLON	
;

//Array
array_decs:array_dec array_decs	
|array_dec	
;
array_dec:identifiers COLON ARRAY LEFTSQUAREBRACKETS INTEGERCONSTANTS COMMA INTEGERCONSTANTS RIGHTSQUAREBRACKETS OF datatype SEMICOLON	
;

//FunctionDeclarations
function_decs:PROCEDURE IDENTIFIER{addProcedure($2);} arguments proceduretype variableconstant_decs BEGIN_ statements END 
IDENTIFIER
{
	if(strcmp($2,$10))
		printf("Wrong Procedure Name:line%d\n",lineCount+1);
	localSymbolCount=0;
} 
SEMICOLON function_decs	
|
;
arguments:LEFTPARENTHESES IDENTIFIER COLON datatype argument RIGHTPARENTHESES	{addSymbol($2);}	
|
;
argument:COMMA IDENTIFIER COLON datatype argument	{addSymbol($2);}
|
;
proceduretype:COLON datatype	
|
;

//Statements
statements:statement	
|statement statements	
;
statement:
IDENTIFIER{checkScope($1);} ASSIGNMENT expression SEMICOLON	
|IDENTIFIER{checkScope($1);} LEFTSQUAREBRACKETS integer_expression RIGHTSQUAREBRACKETS ASSIGNMENT expression SEMICOLON	
|PRINT expression SEMICOLON	
|PRINTLN expression SEMICOLON	
|READ IDENTIFIER{checkScope($2);} SEMICOLON
|RETURN SEMICOLON	
|RETURN expression SEMICOLON	
|IF LEFTPARENTHESES boolean_expression RIGHTPARENTHESES THEN zero_statements ELSE zero_statements END SEMICOLON	
|IF LEFTPARENTHESES boolean_expression RIGHTPARENTHESES THEN zero_statements END SEMICOLON	
|WHILE LEFTPARENTHESES boolean_expression RIGHTPARENTHESES DO zero_statements END SEMICOLON	
|IDENTIFIER{checkProcedure($1);} SEMICOLON 
|IDENTIFIER{checkProcedure($1);} LEFTPARENTHESES commaseparated_expressions RIGHTPARENTHESES SEMICOLON
;
//Expression
expression:MINUS expression %prec UMINUS	
|expression MULTIPLY expression	
|expression DIVIDE expression	
|expression PLUS expression	
|expression MINUS expression	
|LEFTPARENTHESES expression RIGHTPARENTHESES
|constant
|IDENTIFIER{checkall($1);} //Variable or Function
|IDENTIFIER{checkProcedure($1);} LEFTPARENTHESES commaseparated_expressions RIGHTPARENTHESES
|IDENTIFIER{checkScope($1);} LEFTSQUAREBRACKETS integer_expression RIGHTSQUAREBRACKETS
;
commaseparated_expressions:expression
|expression COMMA commaseparated_expressions
;
//IntegerExpression
integer_expression:MINUS integer_expression %prec UMINUS	
|integer_expression MULTIPLY integer_expression	
|integer_expression DIVIDE integer_expression	
|integer_expression PLUS integer_expression	
|integer_expression MINUS integer_expression	
|LEFTPARENTHESES integer_expression RIGHTPARENTHESES
|INTEGERCONSTANTS
|IDENTIFIER{checkall($1);} //Variable or Function
|IDENTIFIER{checkProcedure($1);} LEFTPARENTHESES commaseparated_expressions RIGHTPARENTHESES SEMICOLON	
|IDENTIFIER{checkScope($1);} LEFTSQUAREBRACKETS integer_expression RIGHTSQUAREBRACKETS
;
//BooleanExpression
boolean_expression:expression LESS expression	
|expression LESSEQUAL expression	
|expression EQUAL expression	
|expression GREATEREQUAL expression	
|expression GREATER expression	
|expression NOTEQUAL expression	
|NOT boolean_expression	
|boolean_expression AND boolean_expression	
|boolean_expression OR boolean_expression
|LEFTPARENTHESES boolean_expression RIGHTPARENTHESES	
|BOOLEANCONSTANTS
|IDENTIFIER{checkall($1);} //Variable or Function
|IDENTIFIER LEFTPARENTHESES commaseparated_expressions RIGHTPARENTHESES SEMICOLON{checkProcedure($1);}
|IDENTIFIER LEFTSQUAREBRACKETS integer_expression RIGHTSQUAREBRACKETS{checkScope($1);}
;

//constant
constant:STRINGCONSTANTS
|INTEGERCONSTANTS	
|BOOLEANCONSTANTS	
|REALCONSTANTS	
;
//DataType
datatype:STRING	
|INTEGER	
|REAL	
|BOOLEAN	
;
//Identifiers
identifiers:IDENTIFIER COMMA identifiers	{addSymbol($1);}
|IDENTIFIER	{addSymbol($1);}
;
//ZeroStatements
zero_statements:statements	
|
;
%%

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
