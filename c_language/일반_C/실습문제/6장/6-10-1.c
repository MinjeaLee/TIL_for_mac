#include <stdio.h>

int main(){
    int num, len, check_len, i, pow = 1, result = 0, check_num;
    scanf("%d", &num);

    check_len = num;
    do{
        check_len = check_len / 10;
        len++;
    }while(check_len != 0);
    
    for(i = 0; i < len; i++){
        result = result + (num / pow % 10);
        pow *= 10;
    }

    printf("%d", result);

    return 0;
}