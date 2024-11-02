%{
	#include<stdlib.h>
	#include<string.h>
	#include "y.tab.h"
%}

%%
\n {return NL;}
; {return NL;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
[0-9]+ {return DIGIT;}
[\t]+ {}
[=+*/()-] {return yytext[0];}
. {printf("Invalid character %s\n", yytext);}
%%
