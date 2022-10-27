#include <stdio.h>

int main(){
    int n, price, a, b, i, k;
    int resulta, resultb;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &price, &a, &b);
        resulta = price - a;
        if(resulta < 0){
            resulta = 99999999;
        }
        resultb = price - b;
        if(resultb < 0){
            resultb = 99999999;
        }
        if(resulta < resultb){
            printf("A\n");
        }
        else if ( resulta > resultb){
            printf("B\n");
        }
        else{
            printf("draw\n");
        }
        
    }

    return 0;
}