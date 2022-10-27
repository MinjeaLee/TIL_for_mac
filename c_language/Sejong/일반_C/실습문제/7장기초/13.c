#include <stdio.h>

int main(){
    char x[10];
    int len = sizeof(x)/sizeof(char), i;
    for(i = 0; i < len; i++){
        scanf("%c", &x[i]);
    }
    for(i = 0; i < len; i++){
        if('A' <= x[i] && x[i] <= 'Z'){
            printf(" %c", x[i]);
        }
    }

    return 0;
}