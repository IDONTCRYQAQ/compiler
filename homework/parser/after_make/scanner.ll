%{
#include <iostream>
#include <string>
#include "symbol_table.hh"
#include "driver.hh"
#include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%{
#define LIST     strcat(linebuf,yytext)
#define token(t) {LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i) {LIST; printf("<%s:%d>\n", t, i);}
#define tokenString(t, s) {LIST; printf("<%s:%s>\n", t, s);}
#define MAX_LINE_LENG 256

int line_num = 1;

char linebuf[MAX_LINE_LENG];
%}

%x STR CMT

%%

%{
  yy::location& loc = drv.location;
  loc.step ();
%}

"," return yy::parser::make_COMMA(loc);
":" return yy::parser::make_COLON(loc);
"." return yy::parser::make_PERIOD(loc);
";" return yy::parser::make_SEMICOLON(loc);
"(" return yy::parser::make_LPAREN(loc);
")" return yy::parser::make_RPAREN(loc);
"[" return yy::parser::make_LSBRAC(loc);
"]" return yy::parser::make_RSBRAC(loc);
"{" return yy::parser::make_LBRAC(loc);
"}" return yy::parser::make_RBRAC(loc);

"+" return yy::parser::make_PLUS(loc);
"-" return yy::parser::make_MINUS(loc);
"*" return yy::parser::make_TIMES(loc);
"/" return yy::parser::make_DIVIDE(loc);

"%" return yy::parser::make_MOD(loc);

"<" return yy::parser::make_LT(loc);
"<="    return yy::parser::make_LE(loc);
">="    return yy::parser::make_GE(loc);
">" return yy::parser::make_GT(loc);
"=="    return yy::parser::make_EQ(loc);
"!="    return yy::parser::make_NEQ(loc);

"&&"    return yy::parser::make_AND(loc);
"||"    return yy::parser::make_OR(loc);
"!" return yy::parser::make_NOT(loc);

"<-"  return yy::parser::make_ITER(loc);
"=" return yy::parser::make_ASSIGN(loc);

boolean return yy::parser::make_BOOLEAN(loc);
break return yy::parser::make_BREAK(loc);
char return yy::parser::make_CHAR(loc);
case return yy::parser::make_CASE(loc);
class return yy::parser::make_CLASS(loc);
continue return yy::parser::make_CONTINUE(loc);
def return yy::parser::make_DEF(loc);
do return yy::parser::make_DO(loc);
else return yy::parser::make_ELSE(loc);
exit return yy::parser::make_EXIT(loc);
false return yy::parser::make_CONSTANT_BOOLEAN(false, loc);;
float return yy::parser::make_FLOAT(loc);
for return yy::parser::make_FOR(loc);
if return yy::parser::make_IF(loc);
int return yy::parser::make_INT(loc);
null return yy::parser::make_NULL(loc);
object return yy::parser::make_OBJECT(loc);
print return yy::parser::make_PRINT(loc);
println return yy::parser::make_PRINTLN(loc);
repeat return yy::parser::make_REPEAT(loc);
return return yy::parser::make_RETURN(loc);
string return yy::parser::make_STRING(loc);
to return yy::parser::make_TO(loc);
true return yy::parser::make_CONSTANT_BOOLEAN(true, loc);
type return yy::parser::make_TYPE(loc);
val return yy::parser::make_VAL(loc);
var return yy::parser::make_VAR(loc);
while return yy::parser::make_WHILE(loc);
read return yy::parser::make_READ(loc);

[[:alpha:]][[:alnum:]]* return yy::parser::make_ID(std::string(yytext), loc);
[[:digit:]]+    return yy::parser::make_CONSTANT_INTEGER(std::stoi(yytext), loc);
[-+]?[[:digit:]]+\.[[:digit:]]+([eE][-+]?[[:digit:]]+)? return yy::parser::make_CONSTANT_FLOAT(std::stod(yytext), loc);

'([^'\\\n]|\\.)'  return yy::parser::make_CONSTANT_CHAR(yytext[1], loc);

\"  { yymore();  BEGIN(STR); }    //  string (left quotation mark)
<STR>\"\"  { yymore();  }    //  string (quotation mark in string)
<STR>\"    {
    std::string s;
    for(int i = 1; i < yyleng - 1; ++i) {
        if(yytext[i] == '\"' && yytext[i + 1] == '\"') ++i;
        s += yytext[i];
    }
    BEGIN(INITIAL);
    return yy::parser::make_CONSTANT_STRING(s, loc);
}   //  string (right quotation mark)
<STR>.   { yymore();  } //  string (content)

"/*"    { BEGIN(CMT); }   //  Comment (C++-style) left
<CMT>"*/"   { BEGIN(INITIAL); }   //  Comment (C++-style) right
<CMT>\n { line_num++; loc.lines(yyleng); loc.step();  }
<CMT>. { } //  Comment (C++-style) body

"//".*$   { }   //  Comment (C++-style)

[ \t\r]  { }
\n    { loc.lines(yyleng); loc.step(); }   //  Whitespace (newlines)

<<EOF>> return yy::parser::make_YYEOF(loc);

.   throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));

%%

void driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void driver::scan_end ()
{
  fclose (yyin);
}