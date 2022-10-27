#include <stdio.h>

int main(){
    double a, b, c, d, e;
    int undercount = 0, min = a;
    double avg;
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
    avg = (a+b+c+d+e) / 5;
    if(a > 100 || a < 0 ||b > 100 || b < 0 ||c > 100 || c < 0 ||d > 100 || d < 0 ||e > 100 || e < 0 ){
        printf("Invalid");
    }
    else{
        if(a < b && a < c&& a < d && a < e){
            min = a;

        }
        else if(b < a && b < c&& b < d&&b < e){
            min = b;
        }
        else if(c < a && c < b&&c < d&&c < e){
            min = c;
        }
        else if(d < a && d < b &&d < c &&d < e){
            min = d;
        }
        else{
            min = e;
        }
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
        printf("avg=%.2lf min=%d", avg, min);
    }

    return 0;
}