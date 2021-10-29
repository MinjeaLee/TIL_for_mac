#include <stdio.h>

int main(){
    int num, i, j;
    scanf("%d", &num);
    for(i = 1; i <= num; i++){
        for(j = 1; j <= num; j++)
            if(j == i){
                printf(" X");
            }
            else if(j == (num + 1) - i){
                printf(" X");
            }
            else{
                printf(" O");
            }
        printf("\n");
    }
    

    return 0;
}