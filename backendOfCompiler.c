#include<stdio.h>
#include<string.h>

char arg1[10], arg2[10], op[10], res[10], f[100];

int main(){
    FILE *fp1, *fp2;

    printf("Enter the input filename: ");
    scanf("%[^\n]s", f);

    fp1 = fopen(f, "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL)
    {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    if (fp2 == NULL)
    {
        printf("Error: Could not open output file.\n");
        fclose(fp1);
        return 1;
    }

    while(!feof(fp1)){
        fscanf(fp1, "%s%s%s%s", op, arg1, arg2, res);

        if(strcmp(op, "+") == 0){
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nADD R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", res);
        }
        if (strcmp(op, "*") == 0){
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMUL R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", res);
        }
        if (strcmp(op, "/") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nDIV R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", res);
        }
        if (strcmp(op, "-") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nSUB R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", res);
        }
        if (strcmp(op, "=") == 0)
        {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMOV %s, R0", res);
        }
    }
    fclose(fp1);
    fclose(fp2);
    getchar();

    return 0;
}