%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.2"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <iostream>
    #include <fstream>
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
    std::string object_id;
    auto get_label = [count = 0]() mutable { 
        return std::string("L") + std::to_string(++count); 
    };
    std::vector<std::string> Lfalse, Lexit, Lbegin;
    std::string params_str;
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

%token  BOOLEAN INT CHAR STRING
%token  DO WHILE FOR CONTINUE REPEAT IF ELSE CASE BREAK EXIT
%token  CLASS OBJECT DEF NULL
%token  PRINT PRINTLN RETURN TO TYPE VAL VAR

%token <std::string> ID
%token <bool> CONSTANT_BOOLEAN
%token <int> CONSTANT_INTEGER 
%token <char> CONSTANT_CHAR
%token <std::string> CONSTANT_STRING

%nterm <ValueType> type assign_type assign_type_optional formal_argument 
%nterm <ValueType> expressions function_invocation
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
program: OBJECT { drv.fout << "class "; } 
         ID { drv.fout << $ID << std::endl; object_id = $ID; }
         "{" { drv.symtab.enter_block(); drv.fout << "{" << std::endl; }
         global_declarations methods 
         "}" { drv.symtab.exit_block(); drv.fout << "}" << std::endl; }
       ;

global_declarations : constant_and_variable_declarations
                    ;

methods: methods method
       | method
       ;

method: DEF declaring_id[id] "(" formal_arguments_optional[parameters_type] ")" 
        assign_type_optional[return_type] "{" { 
            drv.symtab.insert($id, {$parameters_type, $return_type});
            drv.symtab.enter_block();
            //jasm
            drv.fout << "  method public static " << type_str($return_type) 
                     << ' ' << $id << '(' << ($id == "main" ? "java.lang.String[]" : params_str) << ')' << std::endl
                     << "  max_stack 15" << std::endl 
                     << "  max_locals 15" << std::endl
                     << "  {" << std::endl;
            params_str.clear();
      }
        constant_and_variable_declarations statements_optional "}" { 
            drv.symtab.exit_block(); 
            //jasm
            drv.fout << "    " << ($return_type == ValueType::VOID ? "return" : "ireturn") << std::endl;
            drv.fout << "  }" << std::endl;
      }
      ;

formal_arguments_optional: formal_arguments { $$.swap($formal_arguments); }
                         | %empty { }
                         ;

formal_arguments: formal_arguments[args] "," formal_argument {
                    $$.swap($args); $$.push_back($formal_argument);
                    //jasm
                    params_str += std::string(", ") + type_str($formal_argument);
                }
                | formal_argument { 
                    $$.push_back($formal_argument);
                    //jasm
                    params_str += type_str($formal_argument);
                }
                ;

formal_argument: ID assign_type { 
                    drv.symtab.default_variable($ID, $assign_type);
                    $$ = $assign_type;
               }
               ;

conditions: IF "(" boolean_expr ")" {
                //jasm
                Lfalse.emplace_back(get_label());
                Lexit.emplace_back(get_label());
                drv.fout << "    ifeq " << Lfalse.back() << std::endl;
          } block_or_simple {
                //jasm
                drv.fout << "    goto " << Lexit.back() << std::endl
                         << Lfalse.back() << ": " << std::endl;
                Lfalse.pop_back();
          } else_optional {
                //jasm
                drv.fout << Lexit.back() << ": " << std::endl;
                Lexit.pop_back();
          }
          ;

else_optional: ELSE block_or_simple 
             | %empty
             ;

loops: WHILE "(" {
        //jasm
        Lbegin.emplace_back(get_label());
        Lexit.emplace_back(get_label());
        drv.fout << Lbegin.back() << ": " << std::endl;
     } boolean_expr ")" {
        //jasm
        drv.fout << "    ifeq " << Lexit.back() << std::endl;
     } block_or_simple {
        //jasm
        drv.fout << "    goto " << Lbegin.back() << std::endl
                 << Lexit.back() << ": " << std::endl;
        Lbegin.pop_back(); Lexit.pop_back();
     }
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
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str($assign_type) << ' ' << $id << std::endl;
                        else
                            drv.fout <<"  " << datasm($constant_exp) 
                                     << "    istore " << drv.symtab.get_number($id) << std::endl;
                    }
                    | VAR declaring_id[id] assign_type { 
                        drv.symtab.insert($id, $assign_type); 
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str($assign_type) << ' ' << $id << std::endl;
                    }
                    | VAR declaring_id[id] "=" constant_exp { 
                        drv.symtab.insert($id, $constant_exp.value_type); 
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << type_str($constant_exp.value_type) << ' ' << $id << std::endl;
                        else 
                            drv.fout << "  " << datasm($constant_exp) 
                                     << "    istore " << drv.symtab.get_number($id) << std::endl;
                    }
                    | VAR declaring_id[id] { 
                        drv.symtab.insert($id);
                        // jasm
                        if(drv.symtab.in_global())
                            drv.fout << "  field static " << "int " << $id << std::endl;
                    }
                    ;

assign_type_optional: assign_type { $$ = $assign_type; }
                    | %empty { $$ = ValueType::VOID; }
                    ;

assign_type: ":" type { $$ = $type; }

type: BOOLEAN   { $type = ValueType::BOOLEAN; }
    | INT    { $type = ValueType::INTEGER; }
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
                        //jasm
                        drv.fout << "    invokestatic " << type_str(drv.symtab.get_type($ID))
                                 << ' ' << object_id << '.' << $ID << '(' << params_str << ')' << std::endl;
                        params_str.clear();
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
                    // jasm
                    drv.fout << (drv.symtab.in_global() ? "  " : "    ");  
                    if( drv.symtab.is_global($id) )
                        drv.fout << "putstatic " << type_str(id_data_type.value_type)
                                 << ' ' << object_id << '.' << $id << std::endl;
                    else 
                        drv.fout << "istore " << drv.symtab.get_number($id) << std::endl;
                }
            }
      }
      | PRINT "(" {
            //jasm
            drv.fout << "    getstatic java.io.PrintStream java.lang.System.out" << std::endl;
      } expressions[type] ")" {
            //jasm
            drv.fout << "    invokevirtual void java.io.PrintStream.print(";
            if($type == ValueType::STRING) drv.fout << "java.lang.String)" << std::endl;
            else drv.fout << type_str($type) << ")" << std::endl;
      }
      | PRINTLN "(" {

            drv.fout << "    getstatic java.io.PrintStream java.lang.System.out" << std::endl;
      } expressions[type] ")" {
            //jasm
            drv.fout << "    invokevirtual void java.io.PrintStream.println(";
            if($type == ValueType::STRING) drv.fout << "java.lang.String)" << std::endl;
            else drv.fout << type_str($type) << ")" << std::endl;
      }
      | RETURN expressions
      | RETURN
      ;

expressions: "-" expressions[arith_expr] %prec UMINUS {
                if($arith_expr == ValueType::INTEGER || $arith_expr == ValueType::FLOAT) $$ = $arith_expr;
                else yy::parser::error(drv.location, "expression not arithmetic\n");
                //jasm
                drv.fout << "    ineg" << std::endl;
           }
           | expressions[l] "*" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    imul" << std::endl;
           }
           | expressions[l] "/" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    idiv" << std::endl;
           }
           | expressions[l] "+" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    iadd" << std::endl;
           }
           | expressions[l] "-" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match") $$ = $l;
                else yy::parser::error(drv.location, m);
                //jasm
                drv.fout << "    isub" << std::endl;
           }
           | expressions[l] "<" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    iflt " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | expressions[l] "<=" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifle " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | expressions[l] "==" expressions[r] {
                if($l == $r) $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifeq " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | expressions[l] ">=" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifge " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | expressions[l] ">" expressions[r] {
                if(std::string m = drv.symtab.arithmetic_match($l, $r); m == "match")
                    $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, m);
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifgt " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | expressions[l] "!=" expressions[r] {
                if($l == $r) $$ = ValueType::BOOLEAN;
                else yy::parser::error(drv.location, "type not match\n");
                //jasm
                std::string l1(std::move(get_label())), l2(std::move(get_label()));
                drv.fout << "    isub" << std::endl
                         << "    ifne " << l1 << std::endl
                         << "    iconst_0" << std::endl
                         << "    goto " << l2 << std::endl
                         << l1 << ": "<<std::endl
                         << "    iconst_1" << std::endl
                         << l2 << ": " << std::endl;
           }
           | "!" expressions[bool_expr] {
                if($bool_expr == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "! required boolean expression\n");
                //jasm
                drv.fout << "    ixor" << std::endl;
           }
           | expressions[l] "&&" expressions[r]  {
                if($l == ValueType::BOOLEAN && $r == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "&& required boolean expression\n");
                //jasm
                drv.fout << "    iand" << std::endl;
           }
           | expressions[l]  "||" expressions[r]  {
                if($l == ValueType::BOOLEAN && $r == ValueType::BOOLEAN) $$ = ValueType::BOOLEAN;
                    else yy::parser::error(drv.location, "|| required boolean expression\n");
                //jasm
                drv.fout << "    ior" << std::endl;
           }
           | CONSTANT_BOOLEAN[b] { 
                $$ = ValueType::BOOLEAN;
                //jasm
                drv.fout << "    iconst_" << ($b ? '1' : '0' ) << std::endl;
           }
           | CONSTANT_INTEGER[i] { 
                $$ = ValueType::INTEGER;
                //jasm
                drv.fout << "    sipush " << $i << std::endl;
           }
           | CONSTANT_CHAR { $$ = ValueType::CHAR; }
           | CONSTANT_STRING[s] { 
                $$ = ValueType::STRING;
                //jasm
                drv.fout << "    ldc \"" << $s << '\"' << std::endl;
           }
           | data_type_id[id] {
                const DataType& id_data_type = drv.symtab.get_data_type($id);
                if(id_data_type.is_array)
                    yy::parser::error(drv.location, "id: " + $id + " is array type\n");
                else $$ = id_data_type.value_type;
                //jasm
                if(id_data_type.is_const)
                    drv.fout << "    " << datasm(drv.symtab.get_data($id));
                else{
                    if(drv.symtab.is_global($id))
                        drv.fout << "    getstatic int " << object_id << '.' << $id << std::endl;
                    else
                        drv.fout << "    iload " << drv.symtab.get_number($id) << std::endl;
                }
           }
           | function_invocation { $$ = $function_invocation; }
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

function_invocation: ID "(" comma_separated_expressions[params] ")" {
                        if(std::string m(std::move(drv.symtab.match_function($ID, $params))); m != "match")
                            yy::parser::error(drv.location, m);
                        else $$ = drv.symtab.get_type($ID);
                        //jasm
                        drv.fout << "    invokestatic " << type_str(drv.symtab.get_type($ID))
                                 << ' ' << object_id << '.' << $ID << '(' << params_str << ')' << std::endl;
                        params_str.clear();
                   }
                   ;

comma_separated_expressions: comma_separated_expressions[params] "," expressions {
                                $$.swap($params); $$.push_back($expressions);
                                //jasm
                                params_str += std::string(", ") + type_str($expressions);
                           }
                           | expressions { 
                               $$.push_back($expressions);
                               //jasm
                               params_str += type_str($expressions);
                           }
                           | %empty { }
                           ;

constant_exp: CONSTANT_BOOLEAN { $$ = { ValueType::BOOLEAN, $CONSTANT_BOOLEAN }; }
            | CONSTANT_INTEGER { $$ = { ValueType::INTEGER, $CONSTANT_INTEGER }; }
            | CONSTANT_CHAR { $$ = { ValueType::CHAR, $CONSTANT_CHAR }; }
            | CONSTANT_STRING { $$ = { ValueType::STRING, $CONSTANT_STRING }; }
            ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}