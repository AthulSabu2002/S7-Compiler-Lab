%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token DIGIT
%token NL
%token PLUS MINUS TIMES DIVIDE

%left PLUS MINUS
%left TIMES DIVIDE

%%
stmt: exp NL       { printf("Value = %d\n", $1); exit(0);}
    ;

exp: DIGIT         { $$ = $1; }
   | exp PLUS exp  { $$ = $1 + $3; }
   | exp MINUS exp  { $$ = $1 - $3; }
   | exp TIMES exp  { $$ = $1 * $3; }
   | exp DIVIDE exp  { $$ = $1 / $3; }
   ;

%%

void yyerror(const char *s) {
    printf("Error\n");
}

int main() {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

