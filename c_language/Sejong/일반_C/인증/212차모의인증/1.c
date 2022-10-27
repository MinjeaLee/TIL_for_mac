#include <stdio.h>

int main(){
    int x[3], num, count, i,j, tmp;
    while(1){
        count = 0;
        for(i = 0; i < 3; i++){
            scanf("%d", &x[i]);
            if(x[i] == 0){
                count++;
            }
        }
        if(count == 3){
            break;
        }
        for(i = 0; i < 2; i++){
            for(j = i + 1; j < 3; j++){
                if(x[j] < x[i]){
                    tmp = x[i];
                    x[i] = x[j];
                    x[j] = tmp;
                }
            }
        }
        for(i = 2; i >= 0; i--){
            printf("%d ", x[i]);
        }
        printf("\n");
    }


    return 0;
}