%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+          { yylval = atoi(yytext); return DIGIT; }
\n              { return NL; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
[ \t]            ;                { }

%%

int yywrap() {
    return 1;
}

