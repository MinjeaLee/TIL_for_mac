#include <stdio.h>

int main(){
    double k, e, m, aver;
    scanf("%lf %lf %lf", &k, &e, &m);
    aver = (k + e + m) / 3;
    if (aver >= 91.5){
        printf("A");
    }
    else if( 85.5 <= aver && aver < 91.5){
        printf("B");
    }
    else if(80.5 <= aver && aver < 85.5){
        printf("C");
    }
    else{
        printf("F");
    }
    if(k == 100 || e == 100 || m == 100){
        printf("Good");
    }
    if (k < 60 || e < 60 || m < 60){
        printf("Bad");
    }
    return 0;
}