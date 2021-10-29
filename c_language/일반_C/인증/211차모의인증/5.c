#include <stdio.h>

int main(){
    int num, result;
    int count_2, count_3;
    scanf("%d", &num);
    while(num > 0){
        result = result * 10;
        result = result + num % 10;
        num = num / 10;
    }
    printf("%d\n", result);
    printf("%d %d", result / 2, result /3);
    return 0;
}