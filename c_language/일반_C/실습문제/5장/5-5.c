#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    if (num % 2 == 0 && num % 3 == 0 && num % 5 == 0){
        printf("A");
    }
    else if (num % 2 == 0 && num % 3 == 0 && num % 5 != 0){
        printf("B");
    }
    else if(num % 2 == 0 && num % 3 != 0 && num % 5 == 0){
        printf("C");
    }
    else if(num % 2 != 0 && num % 3 == 0 && num % 5 == 0){
        printf("D");
    }
    else if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0){
        printf("E");
    }
    else{
        printf("N");
    }
    return 0;
}