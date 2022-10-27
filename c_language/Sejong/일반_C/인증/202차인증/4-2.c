#include <stdio.h>

int main(){
    int n, x[100], i, count = 0, max_count = -1, mul, tmp[100], maxnum[100], j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < n - 1; i++){
        mul = x[i] * x[i + 1];
        if(mul < 0){
            // if(i == n - 2){
            tmp[count] = x[ i];
            tmp[count + 1] = x[i + 1];
            // }
            // else{
            //     tmp[count] = x[i];
            //     tmp[count + 1] = x[i + 1];
            // }
            count++;
        }
        else{
            count = 0;
        }
        if(count >= max_count){
            max_count = count;
            // if(i == n - 2){
            for(j = 0; j < count + 2;j++){
                maxnum[j] = tmp[j];
            }
            // }
            // else{
            //     for(j = 0; j < count + 1;j++){
            //         maxnum[j] = tmp[j];
            //     }
            // }
        }
    }
    printf("%d\n", max_count + 1);
    for(i = 0; i < max_count + 1; i++){
        printf(" %d", maxnum[i]);
    }

    return 0;
}