%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	int yylex();
	void yyerror(const char* msg);
%}

%token DIGIT ID NL
%left '-''+'
%left '*''/'

%%

stmt : exp NL {printf("Valid expression\n");exit(0);}
	 | assignment NL {printf("Valid expression\n");exit(0);}
	 
assignment : ID '=' exp;

exp : exp '+' exp
	| exp '-' exp
	| exp '*' exp
	| exp '/' exp
	| ID
	| DIGIT
	|'(' exp ')'
	;  
	
%%

void yyerror(const char* msg){
	printf("Invalid expression: %s\n", msg);
	exit(0);
}

void main(){
	printf("Enter the expression: ");
	yyparse();
}

int yywrap(){
	return 1;
}
