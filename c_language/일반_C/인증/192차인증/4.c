#include <stdio.h>
//restore github

int main(){
    int x[100], i, n, result;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    if(n % 3 == 0){
        for(i = 0; i < n; i += 3){
            result = 0;
            result = x[i] + x[i + 1] + x[i + 2];
            printf("%d ", result);
        }
    }
    else{
        for(i = 0; i < n - (n % 3); i += 3){
            result = 0;
            result = x[i] + x[i + 1] + x[i + 2];
            printf("%d ", result);
        }
        result = 0;
        for(i = n - (n % 3); i < n; i++){
            result += x[i];
        }
        printf("%d ", result);
    }

    return 0;
}