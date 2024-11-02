%{
	#include "y.tab.h"
%}

%%
\n {return 0;}
[a-zA-Z_][a-zA-Z_0-9]* {return LETTER;}
[0-9] {return DIGIT;}
. {return yytext[0];}
%%
