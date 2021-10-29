#include <stdio.h>

int main(){
    int year;

    scanf("%d", &year);

    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                printf("À±³â");
            }
            printf("Æò³â");
        }
        printf("À±³â");
    }
    else{
        printf("Æò³â");
    }

    return 0;
}