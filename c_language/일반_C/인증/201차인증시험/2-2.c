#include <stdio.h>

int main(){
    char min = 127, min_2 = 127;
    char a;
    while(1){
        scanf("%c", &a);
        if('A' <= a && a <= 'Z'){
            break;
        }
        if(min > a){
            min_2 = min;
            min = a;
        }
        if (a > min && a < min_2){
            min_2 = a;
        }
    } 
    printf("%c%c", min, min_2);
    return 0;  
}