#include <stdio.h>

int main(){
    float a, b, c, d, e;
    int undercount = 0;
    double avg;
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
    avg = (a+b+c+d+e) / 5;
    if(a < 40){
        undercount++;
    }
    if(b < 40){
        undercount++;
    }
    if(c < 40){
        undercount++;
    }
    if(d < 40){
        undercount++;
    }
    if(e < 40){
        undercount++;
    }
    if(undercount >= 3){
        printf("F\n");
    }
    else if(avg >= 90){
        printf("A+\n");
    }
    else if(avg >= 75){
        printf("A\n");
    }
    else if(avg >= 65){
        printf("B+\n");
    }
    else if(avg >= 50){
        printf("B\n");
    }
    else{
        printf("F\n");
    }
    printf("%.2lf", avg);

    return 0;
}