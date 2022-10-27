#include <stdio.h>

int main(){
    double x[10], min;
    int len = sizeof(x)/sizeof(double), i;

    for(i = 0; i < len; i++){
        scanf("%lf", &x[i]);    
    }
    min = x[0];
    for(i = 0; i < len; i++){
        if(min > x[i]){
            min = x[i];
        }
    }
    printf("%.1lf", min);


    return 0;
}