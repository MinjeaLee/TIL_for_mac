#include <stdio.h>

int main(){
    int num, i, j, out_num = 0;
    scanf("%d", &num);

    for(i = 1; i <= num; i++){
        for(j = 0; j < i; j++){
            out_num++;
            printf(" %d", out_num % 10);
        }
        printf("\n");
    }

    return 0;
}