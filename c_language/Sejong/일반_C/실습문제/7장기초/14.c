#include <stdio.h>

int main(){
    char x[10], y[10];
    int len = sizeof(x)/sizeof(char), i;
    
    for(i = 0; i < len; i++){
        scanf("%c", &x[i]);
    }
    getchar();

    for(i = 0; i < len; i++){
        scanf("%c", &y[i]);
    }
    
    for(i = 0; i < len; i++){
        printf(" %c %c", x[i], y[i]);
    }

    return 0;
}