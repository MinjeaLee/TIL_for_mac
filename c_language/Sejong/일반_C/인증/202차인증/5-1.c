#include <stdio.h>

int reverse_num(int num);

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", reverse_num(num));
    return 0;
}

int reverse_num(int num){
    int result = 0;
    int check;
    while(num > 0){
        result *= 10;
        check = num % 10;
        result += check;
        num /= 10;
    }
    return result;
}
