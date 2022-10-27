#include <stdio.h>

int main(){
    int ar[50]={0}, N, count = 0;
    int *p;

    scanf("%d", &N);

    for (p = ar; p < ar+N; p++){
        scanf("%d", p);
    }
    
    for (p = ar; p < ar+N; p++){
        if(*p == 0){
            break;
        }
        else{
            count++;
        }
    }

    printf("%d", count);

    return 0;
}