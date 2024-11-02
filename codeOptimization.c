#include<stdio.h>
#include<time.h>

void func1(){
    for(int i = 0; i < 5; i++){
        printf("Hello World!\n");
    }
}

void func2(){
    printf("Hello World!\n");
    printf("Hello World!\n");
    printf("Hello World!\n");
    printf("Hello World!\n");
    printf("Hello World!\n");
}


int main(){

    clock_t t1, t2;

    t1 = clock();

    func1();

    t1 = clock() - t1;

    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;

    printf("---Normal Loop--\n");
    printf("Time taken: %f\n", time_taken1);

    t2 = clock();

    func2();

    t2 = clock() - t2;

    double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;

    printf("---Unrolled Loop--\n");
    printf("Time taken: %f", time_taken2);

    return 0;
}