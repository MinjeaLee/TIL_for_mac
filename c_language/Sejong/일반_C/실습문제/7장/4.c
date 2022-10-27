#include <stdio.h>

int main(){
    int x[10], i, count_1 = 0, count_2 = 0, count_3 = 0;

    for(i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }

    for(i = 0; i < 10; i++){
        if(x[i] == 1){
            count_1++;
        }
        else if(x[i] == 2){
            count_2++;
        }
        else{
            count_3++;
        }
    }

    printf("1:");
    for(i = 0; i < count_1; i++){
        printf("*");
    }
    printf("\n2:");
    for(i = 0; i < count_2; i++){
        printf("*");
    }
    printf("\n3:");
    for(i = 0; i < count_3; i++){
        printf("*");
    }

    return 0;
}