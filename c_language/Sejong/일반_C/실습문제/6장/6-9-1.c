#include <stdio.h>

int main(){
    int num_check, num, pos, i, j, pow, len = 0, result = 0;
    scanf("%d", &num);
    num_check = num;

    do{
        num_check = num_check / 10;
        len++;
    } while (num_check > 0);
   
    for(i = 0; i < len; i++){
        pow = 1;
        if (i == 0){
            pow = 1;
        }
        for (j = 1; j <= i; j++){
            pow *= 10;
        }
        pos = num / pow % 10;
        if (pos == 3){
            result += 1;
        }
    }
    
    printf("%d", result);

    return 0;
}