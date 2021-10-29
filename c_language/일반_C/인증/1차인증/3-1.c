#include <stdio.h>

int main(){
    int n, num, i = 0;
    int result = 0, num_check, num2;
    scanf("%d", &n);
    while (i < n){
        i++;
        result = 0;
        scanf("%d", &num);
        num2 = num;
        while(num2 > 0){
            num_check = num2 % 10;
            num2 = num2 / 10;
            result += num_check;
        }
        printf("%d %d\n", num, result);
    }

    return 0;
}