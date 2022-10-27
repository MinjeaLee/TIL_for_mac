#include <stdio.h>

int main(){
    int num, t;
    int num_c = 0, i;
    int num_2, num_2_c = 0;
    scanf("%d %d", &num, &t);
    for(i = 1; i <= num; i++){
        if(num % i == 0){
            num_c++;
        }
    }
    printf("%d\n", num_c);
    while(1){
        num_2_c = 0;
        scanf("%d", &num_2);
        if (num_2 <= 0){
            break;
        }
        for(i = 1; i <= num_2; i++){
            if(num_2 % i == 0){
                num_2_c++;
            }
        }
        //printf("%d's numc = %d\n", num_2, num_2_c);
        if(num_2_c == num_c){
            printf("%d\n", num_2);
        }
        else if(num_2_c % t == 0){
            printf("%d\n", num_2);
        }
    }


    return 0;
}