#include <stdio.h>

int main(){
    int num, out_num = 1, i, j;
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            printf(" %d", out_num % 10);
            out_num++;
        }
        printf("\n");
    }

    return 0;
}