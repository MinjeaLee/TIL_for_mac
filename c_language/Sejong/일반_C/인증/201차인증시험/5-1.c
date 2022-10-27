#include <stdio.h>

int main(){
    int num1, num2, i, j;
    int div = 0;
    scanf("%d %d", &num1, &num2);
    for(i = num1 + 1; i < num2 ; i++){
       for(j = 2; j <= i; j++){
           if(i % j == 0){
               div = 1;
           }
       }
       if(!div){
           printf("%d\n", i);
       }
       div = 0;
    }
    return 0;
}