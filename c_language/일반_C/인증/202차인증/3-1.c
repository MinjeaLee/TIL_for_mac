#include <stdio.h>

int main(){
    int x[100], n, i, j, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(x[i] < x[j]){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(x[i] == x[j]){
                x[j] = -1;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(x[i] == -1){
            for(j = i - 1; j > 0; j--){
                if(x[j] != -1){
                    printf("%d ", j + 1);
                    break;
                }
            }
        }
        else{
            printf("%d " , i + 1);
        }
    }
    

    return 0;
}