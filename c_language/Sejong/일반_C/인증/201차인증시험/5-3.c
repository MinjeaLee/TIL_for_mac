#include <stdio.h>

int main(){
    int a, result, resultpp = 0,j , i, k;
    int div = 0;
    while(1){
        result = 0;
        scanf("%d", &a);
        if(a < 0){
            break;
        }
        for(j =2; j < a; j++){
            if(a % j== 0){
                div = 1;
            }
        }
        if(!div){
            printf("%d ", a);
            result = a;
        }
        div = 0;
        if (result){
            k = result;
            while(1){
                k++;
                for(i = 2; i < k; i++){
                    if(k % i == 0){
                        div = 1;  
                    }
                }
                if(!div){
                    printf("%d\n", k);
                    break;
                }
                div = 0;
            } 
        } 
    }
    return 0;
}