#include <stdio.h>
//restore github

int main(){
    int x[100], i, n, result, count, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    while(n >= 2){
        count = 0;
        if(n % 3 == 0){
            for(i = 0; i < n; i += 3){
                result = 0;
                result = x[i] + x[i + 1] + x[i + 2];
                printf("%d ", result);
                x[count] = result;
                count++;
            }
        }
        else{
            for(i = 0; i < n - (n % 3); i += 3){
                result = 0 ;
                result = x[i] + x[i + 1] + x[i + 2];
                printf("%d ", result);
                x[count] = result;
                count++;
            }
            result = 0;
            for(i = n - (n % 3); i < n; i++){
                result += x[i];
            }
            x[count] = result;
            count++;
            printf("%d ", result);
        }
        printf("\n");
        n = count;
    }

    return 0;
}