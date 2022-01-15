#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int main(){
    int (*fp[3])(int, int);
    int num_a, num_b;

    scanf("%d %d",&num_a,&num_b);
    fp[0] = add;
    fp[1] = sub;
    fp[2] = multiply;

    printf("%d %d %d", fp[0](num_a,num_b), fp[1](num_a, num_b), fp[2](num_a, num_b));

    return 0;
}