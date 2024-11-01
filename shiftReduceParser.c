#include <stdio.h>
#include <string.h>

int inputIndex = 0, reduceIndex = 0, stackIndex = 0, grammarIndex = 0, inputLength = 0;
char input[16], action[20], stack[15], shiftAction[10];

void applyReduction();

int main()
{
    puts("GRAMMAR is : \n E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("\nEnter input string : ");
    scanf("%s", input);
    inputLength = strlen(input);
    strcpy(shiftAction, "SHIFT->");
    puts("\nStack \t Input \t Action");

    for (inputIndex = 0, stackIndex = 0; grammarIndex < inputLength; inputIndex++, stackIndex++, grammarIndex++){
        if (input[grammarIndex] == 'i' && input[grammarIndex + 1] == 'd'){
            stack[stackIndex] = input[grammarIndex];
            stack[stackIndex + 1] = input[grammarIndex + 1];
            stack[stackIndex + 2] = '\0';
            input[grammarIndex] = ' ';
            input[grammarIndex + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stack, input, shiftAction);
            applyReduction();
        }
        else{
            stack[stackIndex] = input[grammarIndex];
            stack[stackIndex + 1] = '\0';
            input[grammarIndex] = ' ';
            printf("\n$%s\t%s$\t%ssymbol", stack, input, shiftAction);
            applyReduction();
        }
    }

    return 0;
}

void applyReduction()
{
    strcpy(action, "REDUCE TO E");

    for (reduceIndex = 0; reduceIndex < inputLength; reduceIndex++)
        if (stack[reduceIndex] == 'i' && stack[reduceIndex + 1] == 'd'){
            stack[reduceIndex] = 'E';
            stack[reduceIndex + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            grammarIndex++;
        }

    for (reduceIndex = 0; reduceIndex < inputLength; reduceIndex++)
        if (stack[reduceIndex] == 'E' && stack[reduceIndex + 1] == '+' && stack[reduceIndex + 2] == 'E'){
            stack[reduceIndex] = 'E';
            stack[reduceIndex + 1] = '\0';
            stack[reduceIndex + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            stackIndex -= 2;
        }

    for (reduceIndex = 0; reduceIndex < inputLength; reduceIndex++)
        if (stack[reduceIndex] == 'E' && stack[reduceIndex + 1] == '*' && stack[reduceIndex + 2] == 'E'){
            stack[reduceIndex] = 'E';
            stack[reduceIndex + 1] = '\0';
            stack[reduceIndex + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            stackIndex -= 2;
        }

    for (reduceIndex = 0; reduceIndex < inputLength; reduceIndex++)
        if (stack[reduceIndex] == '(' && stack[reduceIndex + 1] == 'E' && stack[reduceIndex + 2] == ')'){
            stack[reduceIndex] = 'E';
            stack[reduceIndex + 1] = '\0';
            stack[reduceIndex + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, input, action);
            stackIndex -= 2;
        }
}
