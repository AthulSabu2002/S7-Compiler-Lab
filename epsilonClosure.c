#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, j, n, k;
char states[5][10], closure[10][10][10], trans[10][10];

void print_closure(char c_state[5]){
    for(k =0; k < n; k++){
        if(strcmp(c_state, states[k]) == 0){
            printf(" %s ", closure[k][0]);
            print_closure(closure[k][0]);
        }
    }
}


int main(){
    FILE *fp = fopen("transitions.txt", "r");

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the states: ");

    for(i = 0; i < n; i++){
        scanf("%s", states[i]);
    }

    for(i = 0; i < n; i++){
        j = 0;
        while(fscanf(fp, "%s%s%s", trans[0], trans[1], trans[2])!=EOF){
            if(strcmp(trans[1], "e") == 0 && strcmp(trans[0], states[i]) == 0){
                strcpy(closure[i][j], trans[2]);
                j++;
            }
        }
        rewind(fp);
    }

    for(i = 0; i < n; i++){
        printf("\n%s = { %s ", states[i], states[i]);
        print_closure(states[i]);
        printf("}");
    }

    printf("\n");
}