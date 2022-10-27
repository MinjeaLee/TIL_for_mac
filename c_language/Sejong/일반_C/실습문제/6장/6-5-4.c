#include <stdio.h>

int main(){
    int num, i, j;
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        for(j = 2 * (num - i) - 1; j > 0; j--){
            printf("*");
        }
        printf("\n");
        
    }

    return 0;
}