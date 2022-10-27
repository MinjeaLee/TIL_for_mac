#include <stdio.h>

int main(){
    int num, len, len_check, i, num_check, pow, pow_add, result;
    int max = -1, min = 999999999, count;
    while(1){
        count = 0;
        pow = 1;    
        pow_add = 1;    
        result = 0; 
        len = 0;    
        scanf("%d", &num);  
        if(num == 0){
            break;
        }
        len_check = num;    
        do{
            len_check = len_check / 10; 
            len++; 
        } while(len_check != 0);  
        for(i = 0; i < len; i++){ 
            pow_add *= 10; 
        }
        result += num * pow_add;
        for (i = 0; i < len; i++){  
            num_check = num / pow % 10;
            if (num_check == 3){
                count++;
            }
            pow *= 10; 
            pow_add = pow_add / 10;
            result += (num_check * pow_add);  
        }
        printf("%d %d ", result, count * 2);
        if(result > max){
            max = result;
        }
        if( result < min){
            min = result;
        }
        

    }
    
    printf("\n%d %d", min, max);
    return 0;
}