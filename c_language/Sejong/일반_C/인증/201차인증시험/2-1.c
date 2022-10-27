#include <stdio.h>

int main(){
    char a;
    char min = 127;
    while(1){
        scanf("%c", &a);
        if('A' <= a && a <= 'Z'){
            break;
        }
        if ('a' <= a && a <= 'z'){
            if(min > a){
                min = a;
            }
           
        }
    }
    printf("%c", min);

    return 0;
}