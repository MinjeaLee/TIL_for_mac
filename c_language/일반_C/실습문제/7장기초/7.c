#include <stdio.h>

int main(){
    int x[10], i, a, j, count, k = 0;
    for(i = 0; i < 10; i++){
        count = 0;
        scanf("%d", &a);
        for(j = 0; j < 10; j++){
            if(x[j] == a){
                count++;
                break;
            }
        }
        if(count == 0){
            x[k] = a;
            k++;
        }
    }
    for(i = 0; i < k; i++){
        printf(" %d", x[i]);
    }
    return 0;
}
    