#include <stdio.h>

int main(){
    int x[10], i, count = 0, j;
    for(i = 0; i < sizeof(x)/sizeof(int);i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < sizeof(x)/sizeof(int); i++){
        for(j = 0; j < sizeof(x)/sizeof(int); j++){

            if(x[i] < x[j]){
                count++;
            }
        }
        printf(" %d", count);
        count = 0;
    }

    return 0;
}