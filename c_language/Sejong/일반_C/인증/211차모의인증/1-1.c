#include <stdio.h>

int main(){
    float a, b;
    float result;
    scanf("%f %f", &a, &b);
    result = a * 0.4 + b * 0.6;

    
    if (result >= 85.5){
        printf("A ");
    }
    else if(result >= 75.5){
        printf("B ");
    }
    else if(result >= 60){
        printf("C ");
    }
    else{
        printf("F ");
    }
    if(result >= 60 || b >= 90){
        printf("PASS");
    }
    else{
        printf("FAIL");
    }


    return 0;
}