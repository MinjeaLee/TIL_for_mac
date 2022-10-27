#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, total = 0;
    char *str;

    scanf("%d", &n);
    getchar();

    str = (char *)malloc(sizeof(char) * n + 1);
    scanf("%s", str);

    for(int i = 0; i < n - 2; i++){
        if(str[i] == 'c' && str[i + 1]  == 'a' && str[i + 2] == 't'){
            total++;
        }
    }
    printf("%d", total);
    free(str);


    return 0;
}