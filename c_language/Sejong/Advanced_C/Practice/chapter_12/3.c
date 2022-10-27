#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *str, a, b;
    int n, sum_a = 0, sum_b = 0;

    scanf("%d", &n);
    getchar();
    str = (char *) malloc(sizeof(char) * (n+1));
    scanf("%s", str);
    getchar();
    scanf("%c %c", &a, &b);

    for(int i = 0; i < n; i++){
        if(a == str[i]){
            sum_a ++;
        }
        if(b == str[i]){
            sum_b ++;
        }
    }

    printf("%d %d\n", sum_a, sum_b);

    free(str);


    return 0;
}