#include <stdio.h>

int main(){
    int i, n; 
    int count; 
    int b; 
    scanf("%d", &n);
    printf("%d=", n);
    for (i = 2;i <= n;i++) {
        count = 0;
        b = n;
        while (n%i == 0) {
            count++;
            n /= i;
        }
        if (b%i == 0) {
            if (n == 1) {
                printf("%d^%d", i, count);
                break;
            }
            else {
                printf("%d^%d", i, count);
                printf("*");
            }
        }
    }

    return 0;
}