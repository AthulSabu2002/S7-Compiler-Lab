#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isKeyword(char buff[])
{
    int i;
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};

    for (i = 0; i < 32; i++){
        if ((strcmp(buff, keywords[i])) == 0){
            return 1;
        }
    }

    return 0;
}

int main()
{
    FILE *fp;
    char ch, operators[] = "+=-/*%", buff[20];
    int i, j = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL){
        printf("Error while opening file!");
        return 0;
    }
    else{
        while ((ch = fgetc(fp)) != EOF){
            for (i = 0; i < 6; i++){
                if (ch == operators[i]){
                    printf("%c is an operator.\n", ch);
                }
            }
            if (isalnum(ch)){
                buff[j++] = ch;
            }
            else if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == ';') && (j != 0)){
                buff[j] = '\0';
                j = 0;
                if (isKeyword(buff)){
                    printf("%s is a keyword.\n", buff);
                }
                else{
                    printf("%s is an identifier.\n", buff);
                }
            }
        }
        fclose(fp);
    }

    return 0;
}