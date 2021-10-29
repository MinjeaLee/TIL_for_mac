#include <stdio.h>

int main(){
    double x[10];
    int len = sizeof(x) / sizeof(double), i;
    
    for(i = 0; i < len; i++){
        scanf("%lf", &x[i]);
    }
    for(i = 0; i < len; i++){
        if(x[i] > 0){
            printf(" %.1lf", x[i]);
        }
    }

    return 0;
}