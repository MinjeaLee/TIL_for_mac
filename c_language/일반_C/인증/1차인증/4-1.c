#include <stdio.h>

int main(){
    int num, i, j, count = 0;
    while(1){
        
        scanf("%d", &num);
        if (num <= 1){
            break;
        }
        for(i = 2; i < num; i++){
 
            while(num % i == 0){
                num /= i;
                count++;
                
            }
            if(count != 0){
                printf("%d %d ", i, count);
            }
            
            count = 0;
        }
        if(num != 1){
            printf("%d %d", num, 1);
        } 
        printf("\n");
    }
    return 0;
}