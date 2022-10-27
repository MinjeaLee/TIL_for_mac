#include <stdio.h>

int main(){
    int x[100], i, n = 0, num, result, m, j;
    while(1){
        scanf("%d", &num);
        if(num < 0){
            break;
        }
        x[n] = num;
        n++;
    }
    scanf("%d", &m);
    if(n % m == 0){
        for(i = 0; i < n; i += m){
            result = 0;
            for(j = 0; j < m; j++){
                result += x[i + j];
            }
            printf("%d ", result);
        }
    }
    else{
        for(i = 0; i < n - (n % m); i += m){
            result = 0;
            for(j = 0; j < m; j++){
                result += x[i + j];
            }
            printf("%d ", result);
        }
        result = 0;
        for(i = n - (n % m); i < n; i++){
            result += x[i];
        }
        printf("%d ", result);
    }

    return 0;
}