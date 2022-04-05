#include <stdio.h>

int main(){
    int len = 0, check = 1;
    char x[100], y[100];

    scanf("%s\n%s", x, y);

    for(int i = 0; x[i] != '\0'; i++){
        len++;
    }

    for(int i = 0; i < len; i++){
        if(x[i] != y[i]){
            check = 0;
            break;
        }
    }

    printf("%d %d", len, check);

    return 0;
}