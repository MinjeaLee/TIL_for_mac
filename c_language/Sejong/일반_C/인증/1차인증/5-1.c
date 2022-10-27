#include <stdio.h>

int main(){
    int n, k,num, i, count_p = 0, j, div =0;
    scanf("%d", &n);
    scanf("%d", &k);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        for(j = 2; j < num; j++){
            if(num % j == 0){
                div = 1;
                break;
            }
        }
        if(!div && count_p < k && num != 1){
            count_p++;
            printf(" %d", num);
        }
        div = 0;        
    }
    if(count_p == 0){
        printf("0");
    }
    return 0;
}