#include <stdio.h>

int main(){
    int num, i, j;
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        for(j = num - i - 1; j > 0; j--){
            printf(" ");
        }
        for(j = 0; j < 2 * i + 1; j++){
            printf("*");
        }
        for(j = num - i - 1; j > 0; j--){
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}