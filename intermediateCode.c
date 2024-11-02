#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int indexCounter = 1, operatorIndex = 0, assignmentCount = 0, tempVarChar = 90;
char expression[100], leftOperand[15], rightOperand[15];

void findOperators();
void generateIntermediateCode();
void fetchLeftOperand(int);
void fetchRightOperand(int);

struct OperatorInfo
{
    int position;
    char operator;
} operators[15];

int main()
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", expression);
    printf("The intermediate code:\n");
    findOperators();
    generateIntermediateCode();

    return 0;
}

void findOperators()
{
    for (indexCounter = 0; expression[indexCounter] != '\0'; indexCounter++)
    {
        if (expression[indexCounter] == ':')
        {
            operators[operatorIndex].position = indexCounter;
            operators[operatorIndex++].operator= ':';
        }
    }
    for (indexCounter = 0; expression[indexCounter] != '\0'; indexCounter++)
    {
        if (expression[indexCounter] == '/')
        {
            operators[operatorIndex].position = indexCounter;
            operators[operatorIndex++].operator= '/';
        }
    }
    for (indexCounter = 0; expression[indexCounter] != '\0'; indexCounter++)
    {
        if (expression[indexCounter] == '*')
        {
            operators[operatorIndex].position = indexCounter;
            operators[operatorIndex++].operator= '*';
        }
    }
    for (indexCounter = 0; expression[indexCounter] != '\0'; indexCounter++)
    {
        if (expression[indexCounter] == '+')
        {
            operators[operatorIndex].position = indexCounter;
            operators[operatorIndex++].operator= '+';
        }
    }
    for (indexCounter = 0; expression[indexCounter] != '\0'; indexCounter++)
    {
        if (expression[indexCounter] == '-')
        {
            operators[operatorIndex].position = indexCounter;
            operators[operatorIndex++].operator= '-';
        }
    }
}

void generateIntermediateCode()
{
    indexCounter = 1;
    while (operators[indexCounter].operator!= '\0')
    {
        fetchLeftOperand(operators[indexCounter].position);
        fetchRightOperand(operators[indexCounter].position);
        expression[operators[indexCounter].position] = tempVarChar--;
        printf("\t%c := %s %c %s\n", expression[operators[indexCounter].position], leftOperand, operators[indexCounter].operator, rightOperand);
        indexCounter++;
    }
    fetchRightOperand(-1);
    if (assignmentCount == 0)
    {
        fetchLeftOperand(strlen(expression));
        printf("\t%s := %s", rightOperand, leftOperand);
        exit(0);
    }
    printf("\t%s := %c\n", rightOperand, expression[operators[--indexCounter].position]);
}

void fetchLeftOperand(int position)
{
    int charIndex = 0, isFound = 0;
    position--;
    while (position != -1 && expression[position] != '+' && expression[position] != '*' && expression[position] != '=' && expression[position] != '\0' && expression[position] != '-' && expression[position] != '/' && expression[position] != ':')
    {
        if (expression[position] != '$' && isFound == 0)
        {
            leftOperand[charIndex++] = expression[position];
            leftOperand[charIndex] = '\0';
            expression[position] = '$';
            isFound = 1;
        }
        position--;
    }
}

void fetchRightOperand(int position)
{
    int charIndex = 0, isFound = 0;
    position++;
    while (position != -1 && expression[position] != '+' && expression[position] != '*' && expression[position] != '\0' && expression[position] != '=' && expression[position] != ':' && expression[position] != '-' && expression[position] != '/')
    {
        if (expression[position] != '$' && isFound == 0)
        {
            rightOperand[charIndex++] = expression[position];
            rightOperand[charIndex] = '\0';
            expression[position] = '$';
            isFound = 1;
        }
        position++;
    }
}
