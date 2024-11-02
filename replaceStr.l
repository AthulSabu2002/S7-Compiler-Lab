%{
	#include<stdio.h>
	#include<stdio.h>
	
	char str[100];
%}

%%

abc {strcat(str, "ABC");}
[a-zA-Z0-9] {strcat(str, yytext);}
" " {strcat(str, " ");}

\n {printf("%s\n",str);exit(0);}

%%

int main(void){
	printf("Enter the input: ");
	yylex();
	
	return 0;
}


int yywrap(){
	return 1;
}	
