#include <stdio.h>

int main(){
    int m, x[51], i;
    double avg[51]; 
    double result;
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d",& x[i]);
    }
    if(m % 2 == 0){
        printf("Invalid Input");
    }
    else{
        for(i = 0; i < 2; i++){
            avg[i] = x[i];
        }
        for(i = 2; i < m -2; i++){
            result = (x[i - 2] + x[i - 1] + x[i] + x[i +1] + x[i + 2]) / 5.0;
            avg[i] = result;
        }
        for(i = m - 2; i < m; i++){
            avg[i] = x[i];
        }
        for(i = 0; i < m; i++){
            printf(" %0.0lf", avg[i]);
        }
    }
    

    return 0;
}