#include <stdio.h>

int main(){
    int temp;
    scanf("%d", &temp);
    if (temp < 0){
        printf("cold, indoor");
    }
    else if (0 <= temp && temp < 40){
        printf("moderate,outdoor");
    }
    else{
        printf("hot, indoor");
    }

    return 0;
}