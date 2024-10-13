%{
#include<stdio.h>
int n=0;
int k=0,i=0,o=0,num=0;
%}

%%
if|else|while|int|switch|for|char { printf("%s is a keyword\n",yytext);k++;n++;}

_*[a-z]*[A-Z]+[0-9]*|_*[a-z]+[A-Z]*[0-9]* { printf("%s is an  identifier\n",yytext);i++;n++;}

"="|"+"|"-"|"*"|"/"|"<"|">" {printf("%s is an operator\n",yytext);o++;n++;}

[0-9]+ {printf("%s is a number\n",yytext);num++;n++;}

(.) {}

"\t"|"\n" {exit(0);}
%%

int main()
{
printf("Enter the input text: ");
yylex();
return 0;
}

int yywrap()
{
}
