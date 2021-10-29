#include <stdio.h>

int main(){
    char x[5];
    int i, j;
    for(i = 0; i < 5; i++){
        scanf("%c", &x[i]);
    }
    for(i = 0; i < 5; i++){
        for(j = 5 - i; j < 5; j++){
            printf("%c", x[j]);
            
        }
        for(j = 0; j < 5 - i; j++){
            printf("%c", x[j]);
        }
        printf("\n");
    }
    return 0;
}