#include <stdio.h>

int main(){
    int n,num, result, i, num_check, total;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        total = 0;
        result = 0;
        scanf("%d", &num);
        num_check = num;
        printf("%d ", num);
        while(num >0){
            result *= 10;
            num_check = num % 10;
            total += num_check;
            result += num_check;
            num = num / 10;
        }
        printf("%d %d %d\n", total, result, result % 13);
    }
    return 0;
}