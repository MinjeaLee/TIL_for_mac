#include <stdio.h>

int main(){
    char max = 'a', min = 'z';
    char a, b;
    scanf("%c", &a);
    if('a' <= a && a <= 'z'){
        max = a;
        while(1){
            scanf("%c", &b);
            if (b == '0'){
                break;
            }
            if('a' <= b && b <= 'z'){
                if(max < b){
                 max = b;
                }
            }
        }
        printf("%c", max);
    }
    else if('A' <= a && a <= 'Z'){
        min = a;
        while(1){
            scanf("%c", &b);
            if (b == '0'){
                break;
            }
            if('A' <= b && b <= 'Z'){
                if(min > b){
                    min = b;
                }
            }

        }
        printf("%c", min);
    }
    
    
    return 0;
}