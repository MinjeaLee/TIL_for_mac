#include <stdio.h>

int output(int a, int b, int count){
    if((a/count) % 3 == 1 && (b / count) % 3 == 1){
        printf(" ");
    } 
    else{
        if(count / 3 == 0){
            printf("*");
        }
        else{
            output(a, b, count / 3);
        }
    }
}

int main(){
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            output(i, j, n);
        }
        printf("\n");
    }
    
    return 0;
}