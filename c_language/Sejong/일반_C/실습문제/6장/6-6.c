#include <stdio.h>

int main(){
    int num, i, j, out_num;
    scanf("%d", &num);
    i = 0;
    while (i < num){
        i++;
        out_num = i;
        for(j = 0; j < num; j++){
            printf(" %d", out_num % 10);
            out_num++;
        }
        printf("\n");
    }

    return 0;
}