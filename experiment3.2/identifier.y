%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
int valid=1;
%}

%token DIGIT LETTER

%%
start : LETTER s

s : LETTER s
  | DIGIT s
  | 
  ;
	
%%

int main() {
    printf("Enter the token: ");
    yyparse();
    
    if(valid){
    	printf("Valid identifier\n");
    }
    return 0;
}

void yyerror(const char *s) {
 printf("Invalid Identifier\n");
 valid = 0;
}

