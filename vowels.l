%{
	#include<stdio.h>
	int cons = 0, vowels = 0;
%}

%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {cons++;}
\n {printf("%d number of vowels and %d number of consonants\n", vowels, cons);exit(0);}
%%

int main(void){
	printf("Enter the text: ");
	yylex();	
	
	return 0;
}

int yywrap(){
	return 1;
}
