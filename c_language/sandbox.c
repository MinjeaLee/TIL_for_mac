#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void sum(int *result, ...){
    va_list args;
    va_start(args, result);
    int i = 0;
    int sum = 0;
    while(i < 5){
        sum += va_arg(args, int);
        i++;
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d\n", args);
    }
    *result = sum;
    va_end(args);  
}

int main(){
    int *result = malloc(sizeof(int));

    sum(result, 1, 2, 3, 4, 5);

    printf("%d\n", *result);
    return 0;
}