#include <stdio.h>

int main(){
    int x[5], i, tmp;
    for(i = 0; i < 5; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 4; i++){
        if(x[i] > x[i+1]){
            tmp = x[i];
            x[i] = x[i+1];
            x[i+1] = tmp;
        }
    }
    for(i = 0; i < 5; i++){
        printf("%d\n", x[i]);
    }

    return 0;
}