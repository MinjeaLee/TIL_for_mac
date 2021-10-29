#include <stdio.h>

int main(){
    int num, len, len_check, i, num_check, pow, pow_add, result;
    int b2, b3;
    pow = 1;    
    pow_add = 1;    
    result = 0; 
    len = 0;    
    scanf("%d", &num);  
    len_check = num;    
    do{
        len_check = len_check / 10; 
        len++; 
    } while(len_check != 0);  
    
    for(i = 0; i < len; i++){ 
        pow_add *= 10; 
    }
    
    for (i = 0; i < len; i++){  
        num_check = num / pow % 10;
        pow *= 10; 
        
        pow_add = pow_add / 10;
        result += (num_check * pow_add);  
        
    }
    b2 = result / 2;
    b3 = result / 3;
 
    printf("%d\n", result);
    printf("%d %d", b2, b3);
    return 0;
}
