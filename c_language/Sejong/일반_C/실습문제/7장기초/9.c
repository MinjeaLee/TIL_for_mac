#include <stdio.h>

int main(){
    int x[128], n, num, i, result = 0 , pow = 1;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        x[i] = num;
        pow *= 10;
    }
    
    for(i = 0; i < n; i++){
        pow /= 10;
        result += x[i] * pow;
    }
    printf("%d", result);
    return 0;
}