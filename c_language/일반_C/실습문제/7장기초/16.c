#include <stdio.h>

int main(){
    int n, num, i;
    char x[128];
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++){
        scanf("%c", &x[i]);
    }
    
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        printf("x[%d%%%d]=x[%d]=%c\n", num, n, num % n, x[num%n]);
    }

    return 0;
}