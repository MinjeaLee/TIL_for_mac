#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, num;
    char arr[100];
    char *p = arr;

    scanf("%d", &n);

    while(n != 0){
        *p = '0' + n % 10;
        p++;
        n /= 10;
    }
    *p = '\0';

    printf("%s", arr);

    return 0;
}