#include <stdio.h>

int count_3(int x){
    int count = 0, num, num_check;
    for(int i = 1; i <= x; i++){
        num = i;
        while(num != 0){
            num_check = num % 10;
            num /= 10;
            if(num_check == 3){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", count_3(num));
    
}