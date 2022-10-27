#include <stdio.h>

int main(){
    int num,check, i, j, count = 0, max=0, min=99;
    int num_count, max_num=0, min_num=9999999;
    while(1){
        num_count = 0;
        scanf("%d", &num);
        check = num;
        if (num <= 1){
            break;
        }

        for(i = 2; i < num; i++){
            while(num % i == 0){
                num /= i;
                count++;     
            }
            if(count != 0){
                num_count++;
                printf("%d %d ", i, count);
            }            
            count = 0;
        }
        if(num != 1){
            printf("%d %d", num, 1);
            num_count++;
        }
        printf("\n");
        if(num_count >= max){
            max = num_count;
            if(num_count > max&&min_num > check){
                min_num = check;
            }
           
            
        }
        if(num_count <= min && min_num != check){
            min = num_count;
            if(num_count < min&&max_num < check){
                max_num = check;
            }
            
            
        }
    }
    printf("%d %d", min_num, max_num);
    return 0;
}