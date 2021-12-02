%option noyywrap
%{
#include <iostream>
#include "symbol_table.hh"
#define LIST     strcat(linebuf,yytext)
#define token(t) {LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i) {LIST; printf("<%s:%d>\n", t, i);}
#define tokenString(t, s) {LIST; printf("<%s:%s>\n", t, s);}
#define MAX_LINE_LENG 256

int line_num = 1;

char linebuf[MAX_LINE_LENG];
auto symbol_table = create();
%}

%x STR CMT

%%

[,:.;()\[\]{}] { char* t = (char*)malloc( (yyleng + 3) * sizeof(char) );
                 t[0] = '\''; strcat(t, yytext); t[yyleng + 1] = '\''; t[yyleng + 2] = '\0';
                 token(t); free(t);  }
[-+/*<>!%=!] { token(yytext);  }
"<="    { token(yytext); }
">="    { token(yytext); }
"=="    { token(yytext); }
"!="    { token(yytext); }
"&&"    { token(yytext); }
"||"    { token(yytext); }
"<-"    { token(yytext); }

boolean     { token("BOOLEAN"); }
break       { token("BREAK"); }
char        { token("CHAR"); }
case        { token("CASE"); }
class       { token("CLASS"); }
continue    { token("CONTINUE"); }
def         { token("DEF"); }
do          { token("DO"); }
else        { token("ELSE"); }
exit        { token("EXIT"); }
false       { token("FALSE"); }
float       { token("FLOAT"); }
for         { token("FOR"); }
if          { token("IF"); }
int         { token("INT"); }
null        { token("NULL"); }
object      { token("OBJECT"); }
print       { token("PRINT"); }
println     { token("PRINTLN"); }
repeat      { token("REPEAT"); }
return      { token("RETURN"); }
string      { token("STRING"); }
to          { token("TO"); }
true        { token("TRUE"); }
type        { token("TYPE"); }
val         { token("VAL"); }
var         { token("VAR"); }
while       { token("WHILE"); }
read        { token("READ"); }

[[:alpha:]][[:alnum:]]*    { char* t = (char*)malloc( (yyleng + 2) * sizeof(char) );
                             t[0] = ' '; strcat(t, yytext); 
                             tokenString("id", t); free(t); 
                             symbol_table->insert(yytext);  }   //  Identifiers
[[:digit:]]+   { tokenInteger("int", (int)strtol(yytext, NULL, 10));  } //  Integer Constants
[-+]?[[:digit:]]+\.[[:digit:]]+([eE][-+]?[[:digit:]]+)?   { token(yytext);  } //  Real Constants

\"  { yymore();  BEGIN(STR); }    //  string (left quotation mark)
<STR>\"\"  { yymore();  }    //  string (quotation mark in string)
<STR>\"    {
    char* s = (char *)malloc(sizeof(yyleng * sizeof(char))), *si = s;
    for(int i = 1; i < yyleng; ++i) {
        if(yytext[i] == '\"' && yytext[i + 1] == '\"') ++i;
        *si++ = yytext[i];
    }   *--si = '\0';
    tokenString("string",s); free(s);
    
    BEGIN(INITIAL);
}   //  string (right quotation mark)
<STR>.   { yymore();  } //  string (content)

"/*"    { LIST; BEGIN(CMT); }   //  Comment (C++-style) left
<CMT>"*/"   { LIST; BEGIN(INITIAL); }   //  Comment (C++-style) right
<CMT>\n { printf("%d: %s\n", line_num++, linebuf); linebuf[0] = '\0'; }
<CMT>. { LIST;  } //  Comment (C++-style) body

"//".*$   { LIST; }   //  Comment (C++-style)

[ \t]+  { LIST; }
\n    { printf("%d: %s\n", line_num++, linebuf); linebuf[0] = '\0'; }   //  Whitespace (newlines)

<<EOF>> { LIST; printf("%d: %s\n", line_num, linebuf); return 0;}

.       { LIST; printf("%d:%s\n", line_num, linebuf); printf("bad character:'%s'\n",yytext); exit(-1); }

%%

int main(int argc, char *argv[]) {
    if(argc == 2) yyin = fopen(argv[1], "r");
    yylex();
    std::cout << std::endl;
    symbol_table->dump();
}