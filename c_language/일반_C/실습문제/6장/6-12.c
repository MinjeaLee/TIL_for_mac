#include <stdio.h>

int main(){
    int num, result, k;
    scanf("%d", &num);
    k = 0;
    for(;;){
        k++;
        if (k - 1 == num){
            break;
        }
        result += k;
    }
    printf("%d", result);

    return 0;
}