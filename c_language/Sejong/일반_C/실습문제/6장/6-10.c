#include <stdio.h>

int main(){
    int num, len_check, len, i, pow, result;
    scanf("%d", &num);
    while(1){
        len_check = num;
        pow = 1;
        result = 0;
        len = 0;
        do{
            len_check = len_check / 10;
            len++;
        }while(len_check != 0);
        if(len == 1){
            break;
        }
        for(i = 0; i < len; i++){
            result += num / pow % 10;
            pow *= 10;
        }
        num = result;
    }
    printf("%d", num);

    return 0;
}