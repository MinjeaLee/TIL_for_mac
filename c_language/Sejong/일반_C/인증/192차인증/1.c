#include <stdio.h>
//restore github
int main(){
    int num, start, i, j, k, tmp;
    scanf("%d %d", &num, &start);
    for(i = 0; i < num; i++){
        tmp = start;
        for(j = 0; j < ((2 * num - 1) - (2 * i + 1))/2; j++){
            printf(" ");
        }
        for(j = 0; j < 2 * i + 1; j++){
            k = tmp % 10;
            printf("%d", k);
            tmp++;
        }
        printf("\n");
    }

    return 0;
}