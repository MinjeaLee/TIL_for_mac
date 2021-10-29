#include <stdio.h>

int main(){
    int num, len = 0;
    double total = 0;
    while(1){
        scanf("%d", &num);
        if(num <= 0){
            break;
        }
        else if(num > 100){
            continue;
        }
        else{
            len++;
            total += num;
        }
    }
    printf("%.0lf %.2lf %d", total, total / len, len);
    return 0;
}