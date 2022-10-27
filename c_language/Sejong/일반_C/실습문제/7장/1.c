#include <stdio.h>

int main(){
    int x[5], avg = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &x[i]);
        avg += x[i];
    }
    avg /= 5;
    for(int i = 0; i <5; i++){
        if (x[i] > avg){
            printf("%d\n", x[i]);
        }
    }
    

    return 0;
}