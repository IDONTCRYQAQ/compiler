%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.2"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <iostream>
    #include <string>
    #include "symbol_table.hh"
    class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed  //  provides a more verbose and specific error message string instead of just plain "syntax error"
%define parse.lac full

%code {
    #include "driver.hh"
}

%define api.token.prefix {TOK_}
/* tokens */
%token
    COMMA   ","
    COLON   ":"
    PERIOD  "."
    SEMICOLON   ";"
    LPAREN  "("
    RPAREN  ")"
    LSBRAC  "["
    RSBRAC  "]"
    LBRAC   "{"
    RBRAC   "}"
%token
    PLUS    "+"
    MINUS   "-"
    TIMES   "*"
    DIVIDE  "/"
%token
    MOD "%"
    ITER "<-"
    ASSIGN "="
%token
    LT  "<"
    LE  "<="
    GE  ">="
    GT  ">"
    EQ  "=="
    NEQ "!="
%token
    AND "&&"
    OR  "||"
    NOT "!"

%token  BOOLEAN INT FLOAT CHAR STRING
%token  DO WHILE FOR CONTINUE REPEAT IF ELSE CASE BREAK EXIT
%token  CLASS OBJECT DEF NULL
%token  PRINT PRINTLN RETURN TO TYPE VAL VAR READ

%token <std::string> ID
%token <bool> CONSTANT_BOOLEAN
%token <int> CONSTANT_INTEGER 
%token <float> CONSTANT_FLOAT
%token <char> CONSTANT_CHAR
%token <std::string> CONSTANT_STRING

%nterm <ValueType> type assign_type assign_type_optional formal_argument 
%nterm <ValueType> expressions integer_expression function_invocation array_reference
%nterm <Data> constant_exp
%nterm <std::string> declaring_id data_type_id
%nterm < std::vector<ValueType> > comma_separated_expressions formal_arguments formal_arguments_optional

%left "||"
%left "&&"
%left "!"
%left "<" "<=" "==" ">=" ">" "!="
%left "+" "-"
%left "*" "/"

%nonassoc UMINUS

%%      
program: OBJECT ID "{" { drv.symtab.enter_block(); } constant_and_variable_declarations methods "}"
       ;

methods: methods method
       | method
       ;

method: DEF declaring_id[id] "(" formal_arguments_optional[parameters_type] ")" 
        assign_type_optional[return_type] "{" { 
            drv.symtab.insert($id, {$parameters_type, $return_type});
            drv.symtab.enter_block(); 
      }
        constant_and_variable_declarations statements_optional "}" { 
            drv.symtab.exit_block(); 
      }
      ;

formal_arguments_optional: formal_arguments { $$.swap($formal_arguments); }
                         | %empty { }
                         ;

formal_arguments: formal_arguments[args] "," formal_argument {
                    $$.swap($args); $$.push_back($formal_argument);
                }
                | formal_argument { $$.push_back($formal_argument); }
                ;

formal_argument: ID assign_type { 
                    drv.symtab.default_variable($ID, $assign_type);
                    $$ = $assign_type;
               }
               ;

conditions: IF "(" boolean_expr ")" block_or_simple
          | IF "(" boolean_expr ")" block_or_simple ELSE  block_or_simple
          ;

loops: WHILE "(" boolean_expr ")" block_or_simple
     | FOR "(" ID "<-" CONSTANT_INTEGER TO CONSTANT_INTEGER ")" {
            drv.symtab.default_variable($ID); 
     } block_or_simple
     ;

boolean_expr: expressions {
                if($expressions != ValueType::BOOLEAN)
                    yy::parser::error(drv.location, "expression not boolean\n");
            }
            ;
            
block_or_simple: block
               | simple
               ;

block: "{" { drv.symtab.enter_block(); } 
       constant_and_variable_declarations statements "}" { drv.symtab.exit_block(); }
     ;

constant_and_variable_declarations: constant_and_variable_declarations constant_and_variable_declaration
                                  | %empty
                                  ;

constant_and_variable_declaration: constant_declaration
                                 | variable_declaration
                                 ;

constant_declaration: VAL declaring_id[id] assign_type_optional[type] "=" constant_exp[data] {
                        if($type == ValueType::VOID || $type == $data.value_type)
                            drv.symtab.insert($id, $data.value, $data.value_type);
                        else yy::parser::error(drv.location, std::string($id) + " type not matched\n");
                    }
                    ;
                    
variable_declaration: VAR declaring_id[id] assign_type "=" constant_exp {
                        if($assign_type == $constant_exp.value_type)
                            drv.symtab.insert($id, $assign_type);
                        else yy::parser::error(drv.location, std::string($id) +  " type not matched\n");
                    }
                    | VAR declaring_id[id] assign_type "[" CONSTANT_INTEGER "]" {   // Arrays declaration
                        drv.symtab.insert($id, $assign_type, true);
                    }
                    | VAR declaring_id[id] assign_type { drv.symtab.insert($id, $assign_type); }
                    | VAR declaring_id[id] "=" constant_exp { drv.symtab.insert($id, $constant_exp.value_type); }
                    | VAR declaring_id[id] { drv.symtab.insert($id); }
                    ;

assign_type_optional: assign_type { $$ = $assign_type; }
                    | %empty { $$ = ValueType::VOID; }
                    ;

assign_type: ":" type { $$ = $type; }

type: BOOLEAN   { $type = ValueType::BOOLEAN; }
    | INT    { $type = ValueType::INTEGER; }
    | FLOAT  { $type = ValueType::FLOAT; }
    | CHAR   { $type = ValueType::CHAR; }
    | STRING     { $type = ValueType::STRING; }
    ;

declaring_id: ID {
                if( drv.symtab.is_declared($ID) ) 
                yy::parser::error(drv.location, std::string($ID) + " redeclared\n");
                $$ = $ID;
            }
            ;

statements_optional: statements
                   | %empty
                   ;

statements: statements statement
          | statement
          ;

statement: simple
         | block
         | conditions
         | loops
         | procedure_invocations
         ;

procedure_invocations: ID "(" comma_separated_expressions[params] ")" {
                        if(std::string m(std::move(drv.symtab.match_procedure($ID, $params))); m != "match")
                            yy::parser::error(drv.location, m);
                     }
                     | ID {
                        if(std::string m(std::move(drv.symtab.match_procedure($ID, {}))); m != "match")
                            yy::parser::error(drv.location, m);
                     }
                     ;


simple: data_type_id[id] "=" expressions {
switch (drv.symtab.lookup($id)) {
                case ClassType::NIL :
                    yy::parser::error(drv.location, "id: " + $id + " not declared\n" );
                    break;
                case ClassType::FUNCTION :
                    yy::parser::error(drv.location, "can't assign value to funcion\n" );
                case ClassType::DATA : {
                    const DataType& id_data_type = drv.symtab.get_data_type($id);
                    if(id_data_type.is_array)
                        yy::parser::error(drv.location, "id: " + $id + " is array type\n");
                    if(id_data_type.value_type != $expressions)
                        yy::parser::error(drv.location, "type not matched\n" );
                    if(id_data_type.is_const)
                        yy::parser::error(drv.location, "can't reassigned constant val\n" );
                }
            }
      }
      | array_reference "=" expressions {
          if($array_reference != $expressions)
            yy::parser::error(drv.location, "type not matched on array\n" );
      }
      | PRINT "(" expressions ")"
      | PRINTLN "(" expressions ")"
      | READ ID
      | RETURN expressions
      | RETURN
      ;

expressions: "-" expressions[arith_expr] %prec UMINUS {
                if($arith_expr == ValueType::INTEGER || $arith_expr == ValueType::FLOAT) $$ = $arith_expr;
                else yy::parser::error(drv.location, "expression not arithmetic\n");
           }
           | expressions[l] "*" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "/" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "+" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "-" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "<" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "<=" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "==" expressions[r] {
                if($l == $r) $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
           }
           | expressions[l] ">=" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] ">" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
           }
           | expressions[l] "!=" expressions[r] {
                if($l == $r) $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
           }
           | "!" expressions[bool_expr] {
                if($bool_expr == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "! required boolean expression\n");
           }
           | expressions[l] "&&" expressions[r]  {
                if($l == ValueType::BOOLEAN && $r == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "&& required boolean expression\n");
           }
           | expressions[l]  "||" expressions[r]  {
                if($l == ValueType::BOOLEAN && $r == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "|| required boolean expression\n");
           }
           | CONSTANT_BOOLEAN { $$ = ValueType::BOOLEAN; }
           | CONSTANT_INTEGER { $$ = ValueType::INTEGER; }
           | CONSTANT_FLOAT { $$ = ValueType::FLOAT; }
           | CONSTANT_CHAR { $$ = ValueType::CHAR; }
           | CONSTANT_STRING { $$ = ValueType::STRING; }
           | data_type_id[id] {
                const DataType& id_data_type = drv.symtab.get_data_type($id);
                if(id_data_type.is_array)
                    yy::parser::error(drv.location, "id: " + $id + " is array type\n");
                else $$ = id_data_type.value_type;
           }
           | function_invocation { $$ = $function_invocation; }
           | array_reference { $$ = $array_reference; }
           ;

array_reference: data_type_id[id] "[" integer_expression "]" {
                    const DataType& id_data_type = drv.symtab.get_data_type($id);
                    if(!id_data_type.is_array)
                        yy::parser::error(drv.location, "id: " + $id + " is not array\n");
                    else $$ = id_data_type.value_type;
               }
               ;

data_type_id: ID {
                const ClassType& id_class = drv.symtab.lookup($ID);
                if(id_class == ClassType::NIL)
                    yy::parser::error(drv.location, "id: " + $ID + " is not declared\n");
                else if(id_class != ClassType::DATA)
                    yy::parser::error(drv.location, "id: " + $ID + " is not a data\n");
                else $$ = $ID;
            }
            ;

integer_expression: expressions { 
                    if($expressions == ValueType::INTEGER) $$ = ValueType::INTEGER;
                    else yy::parser::error(drv.location, "expression not integer\n");
                  }
                  ;

function_invocation: ID "(" comma_separated_expressions[params] ")" {
                        if(std::string m(std::move(drv.symtab.match_function($ID, $params))); m != "match")
                            yy::parser::error(drv.location, m);
                        else $$ = drv.symtab.get_type($ID);
                   }
                   ;

comma_separated_expressions: comma_separated_expressions[params] "," expressions {
                                $$.swap($params); $$.push_back($expressions);
                           }
                           | expressions { $$.push_back($expressions); }
                           | %empty { }
                           ;

constant_exp: CONSTANT_BOOLEAN { $$ = { ValueType::BOOLEAN, $CONSTANT_BOOLEAN }; }
            | CONSTANT_INTEGER { $$ = { ValueType::INTEGER, $CONSTANT_INTEGER }; }
            | CONSTANT_FLOAT { $$ = { ValueType::FLOAT, $CONSTANT_FLOAT }; }
            | CONSTANT_CHAR { $$ = { ValueType::CHAR, $CONSTANT_CHAR }; }
            | CONSTANT_STRING { $$ = { ValueType::STRING, $CONSTANT_STRING }; }
            ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}