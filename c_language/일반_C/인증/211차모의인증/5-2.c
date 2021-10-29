#include <stdio.h>

int main(){
    int num, result, num_check, len, len_check;
    int pow, i, max = 0, min = 999999, pow_add;
    int count_3;
    while(1){
        len = 0;
        pow = 1;
        count_3 = 0;
        pow_add = 1;
        scanf("%d", &num);
        if(num == 0){
            break;
        }

        len_check = num;
        
        do{
            len_check = len_check / 10;
            len++;
        } while(len_check > 0);
        for(i = 0; i < len; i++){
            pow_add *= 10;
        }
        result = num * pow_add;
        for(i = 0; i < len; i++){
            num_check = num / pow % 10;
            pow *= 10;
            if (num_check == 3){
                count_3++;
            }
            pow_add /= 10;
            result += num_check * pow_add;
            
        }
        printf("%d %d ",result, count_3 * 2);
        if(result > max){
            max = result;
        }
        if(result < min){
            min = result;
        }
    }
    printf("\n%d %d", min, max);

    return 0;
}