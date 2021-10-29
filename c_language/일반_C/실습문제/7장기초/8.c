#include <stdio.h>

int main(){
    int num, result, len = 0, list[128], i, len_check;
    scanf("%d", &num);
    len_check = num;
    do{
        len_check /= 10;
        len++;
    }while(len_check > 0);

    for(i = 0; i < len; i++){
        list[i] = num % 10;
        num /= 10;
    }
    for(i = 0; i < len; i++){
        printf(" %d", list[i]);
    }

    return 0;
}