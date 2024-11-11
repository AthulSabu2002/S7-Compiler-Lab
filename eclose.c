#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, visited[10] = {0};
char state[10][10], closure[10][10][10], trans[10][10];

void print_closure(char c_state[5]){
    int k, j, m;

    for(k = 0; k < n; k++){
        if(strcmp(c_state, state[k]) == 0){
            for(j = 0; j < 10 && closure[k][j][0]!='\0'; j++){
                int index = -1;
                for(m = 0; m < n; m++){
                    if(strcmp(closure[k][j], state[m]) == 0){
                        index = m;
                        break;
                    }
                }

                if(index != -1 && !visited[index]){
                    printf(" %s", closure[k][j]);
                    print_closure(closure[k][j]);
                }
            }
        }
    }
}

int main(){
    int j, i;

    FILE *fp = fopen("transitions.txt", "r");

    if(fp == NULL){
        printf("Error opening file\n");
        return 0;
    }

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the states: ");
    for(i = 0; i < n; i++){
        scanf("%s", state[i]);
    }

    for(i =0; i < n; i++){
        j=0;
        while(fscanf(fp, "%s%s%s", trans[0], trans[1], trans[2])!=EOF){
            if(strcmp(trans[1], "e") == 0 && strcmp(state[i], trans[0]) == 0){
                strcpy(closure[i][j], trans[2]);
                j++;
            }
        }

        rewind(fp);
    }

    for(i = 0; i < n; i++){
        memset(visited, 0, sizeof(visited));
        printf("\n%s = { %s", state[i], state[i]);
        visited[i] = 1;
        print_closure(state[i]);
        printf(" }");
    }

    printf("\n");

    return 0;
}