#include <stdio.h>

int main(){
    int num, i = 0;
    scanf("%d", &num);
    while (i <= num)
    {   
        i++;
        if(num % i == 0){
            printf("%d", i);
        }
        if(i == num){
            break;
        }
        if(num % i == 0){
            printf(" ");
        }

    }
    return 0;
}