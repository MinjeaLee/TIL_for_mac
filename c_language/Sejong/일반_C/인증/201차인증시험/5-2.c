#include <stdio.h>

int main(){
    int a;
    int div = 0;
    int num_count = 0, prime_count = 0, j;
    while(1){
        scanf("%d", &a);
        num_count++;
        if(num_count == 1 && a < 0){
            printf("none");
            break;
        }
        else if(a < 0){
            break;
        }
        for(j = 2; j < a; j++){
            if(a % j == 0){
                div = 1;
            }
        }
        if(!div){
            printf("%d\n", a);
            prime_count++;
        }
        div = 0;
    }
    if(prime_count == 0 &&!(num_count == 1 && a < 0)){
        printf("none");
    }
    return 0;
}