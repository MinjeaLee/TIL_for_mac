#include <stdio.h>

int main(){
    int x[5], i, max_1, max_2, min = 9999;
    for(i = 0; i < 5; i++){
        scanf("%d", &x[i]);
        if (min > x[i]){
            min = x[i];
        }
    }
    max_1 = min;
    max_2 = min;
    for(i = 0; i < 5; i++){
        if(max_1 <= x[i]){
            max_2 = max_1;
            max_1 = x[i];
        }
        else if(max_2 < x[i]){
            max_2 = x[i];
        }
    }
    printf("%d\n%d", max_1, max_2);

    return 0;
}