#include <stdio.h>

int main(){
    double x[10];
    int i, j, count, len = sizeof(x)/sizeof(double);
    for(i = 0; i < len; i++){
        scanf("%lf", &x[i]);
    }
    for(i = 0; i < len; i++){
        count = 0;
        for(j = 0; j <len; j++){
            if(x[i] > x[j]){
                count++;
            }
        }
        printf(" %d", count);
    }


    return 0;
}