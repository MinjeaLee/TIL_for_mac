#include <stdio.h>

int main(){
    int n, x[100], i, count = 0, max_count = -1, mul;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < n - 1; i++){
        mul = x[i] * x[i + 1];
        if(mul < 0){
            count++;
        }
        else{
            count = 0;
        }
        if(count > max_count){
            max_count = count;
        }
    }
    printf("%d", max_count + 1);


    return 0;
}