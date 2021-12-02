%{
#include "lex.yy.c"
#include <iostream>
#define Trace(t) cout << t << endl
int yylex();
using namespace std;

void yyerror(string t);
bool Mainexist = false;
%}

%token COM COL PER SEM PAR_L PAR_R SBRA_L SBRA_R CBRA_L CBRA_R

%token ADD SUB MUL DIV REM
%token RBIG RBEQ LBIG LBEQ EQ NEQ

%token AND OR NOT ASS ARR

%token BREAK CLASS CONTINUE DEF IF ELSE EXIT
%token CASE DO FOR WHILE
%token nULL PRINT PRINTLN REPEAT RETURN TO READ

%token TYPE VAL VAR OBJECT

%token BOOLEAN TRUE FALSE CHAR INT FLOAT STRING

%union {
    bool boolVal;
    int intVal;
    float floatVal;
    char charVal;
    char* stringVal;
}

%token <boolVal> BOOL_VAL
%token <intVal> INT_VAL
%token <floatVal> FLOAT_VAL
%token <charVal> CHAR_VAL
%token <stringVal> STRING_VAL
%token <stringVal> ID


%left OR AND NOT
%left RBIG RBEQ LBIG LBEQ EQ NEQ
%left ADD SUB
%left MUL DIV REM
%nonassoc UMINUS

%type <intVal>expression

%%

/* program */
program: OBJECT_declaration
       ;

/* object */
OBJECT_declaration: OBJECT ID CBRA_L variable_constant_declarations methods_declarations CBRA_R
                  ;


/* type */
optional_assignment_type: 
	     		| assignment_type
	     		;

assignment_type: COL type
               ;

type: BOOLEAN  
    | INT     
    | FLOAT    
    | CHAR   
    | STRING
    ;

/* constant */
constant_declaration: VAR ID assignment_type ASS constant_expression
		    | VAR ID ASS constant_expression
                    ;

optional_constant_expression: constant_expression
		    	    |
                    	    ;

constant_expression: BOOL_VAL  
                   | INT_VAL   
                   | FLOAT_VAL  
                   | CHAR_VAL  
                   | STRING_VAL
                   ;


/* variable */
variable_declaration: VAR ID optional_assignment_type ASS optional_constant_expression
		    | VAR ID optional_assignment_type
        	    ;

/* variable & constant */
variable_constant_declarations: variable_constant_declaration variable_constant_declarations
                             |
                             ;

variable_constant_declaration: constant_declaration
                             | variable_declaration
                             | array_declaration
                             ;

/* array */
array_declaration: VAR ID COL assignment_type SBRA_L INT_VAL SBRA_R
     		 ;

array_reference: ID SBRA_L integer_expression SBRA_R
	       ;

/* methods */
methods_declarations: method_declarations methods_declarations
                    |
		    ;

method_declarations: DEF ID PAR_L formal_arguments PAR_R optional_assignment_type CBRA_L variable_constant_declarations statements_declarations CBRA_R
                   ;


/* ? formal_arguments */
formal_arguments: formal_argument COM formal_arguments
		|
                ;

formal_argument: ID COL assignment_type
	       ;
	       

/* statements */
statement_declarations: simple
         	      | block
         	      | conditional
         	      | loops
         	      | procedure_invocation
         	      ;

statements_declarations: 
		       |statement_declarations statements_declarations
		       ;

/* simple */

simple: ID ASS expression
      | ID SBRA_L integer_expression SBRA_R ASS expression
      | PRINT PAR_L expression PAR_R
      | PRINTLN PAR_L expression PAR_R
      | READ ID
      | RETURN
      | RETURN expression
      ;


/* expression */
expression: expression ADD expression{ yyerror("These types are add.");
                                        }
	  | expression SUB expression
	  | expression MUL expression
	  | expression DIV expression
	  | expression REM expression
	  | expression RBIG expression
	  | expression RBEQ expression
	  | expression LBIG expression
	  | expression LBEQ expression
	  | expression EQ expression
	  | expression NEQ expression
	  | expression OR expression
	  | expression AND expression
	  | expression NOT expression
	  | BOOL_VAL
	  | INT_VAL
	  | FLOAT_VAL
	  | CHAR_VAL
	  | STRING_VAL
	  | PAR_L expression PAR_R
	  | DIV expression %prec UMINUS
	  | array_reference
	  | ID
	  | function_invocation
	  ;

integer_expression: expression
		  ;
boolean_expression: expression
		  ;

comma_separated_expressions: expression COM comma_separated_expressions
			   | expression
			   ;

/* function invocation */
function_invocation: ID PAR_L PAR_R 
		   | ID PAR_L comma_separated_expressions PAR_R
		   ;

/* block */
block: CBRA_L block_constant_variable_statements CBRA_R
     ;

block_constant_variable_statements: 
                                  | block_constant_variable_statement block_constant_variable_statements
                                  ;

block_constant_variable_statement: constant_declaration
                                 | variable_declaration
                                 | statement_declarations
                                 ;
block_or_simple: block
	       | simple
	       ;

/* conditional */ 
conditional: IF PAR_L boolean_expression PAR_R block_or_simple
	   | IF PAR_L boolean_expression PAR_R block_or_simple ELSE block_or_simple
	   ;

/* loops */
loops: while_loop
     | for_loop
     ;

while_loop: WHILE PAR_L boolean_expression PAR_R block_or_simple
          ;

for_loop: FOR PAR_L ID ARR INT_VAL TO INT_VAL PAR_R block_or_simple
        ;

/* procedure invocation */
procedure_invocation: ID
		    | ID PAR_L comma_separated_expressions PAR_R
		    ;

%%
void yyerror(string t) {
    cout << "Warning : " << lineNum << " : " << t << endl;
	
}

int main (int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
