#include <stdio.h>

int main(){
    int n1, n2, i, j;
    int div = 0;
    scanf("%d %d", &n1, &n2);
    for(i = n1; i <= n2; i++){
        for(j = 2; j < i ; j++){
            if(i % j == 0){
                div = 1;
                break;
            }
        }
        if(!div){
            printf("1\n");
        }
        div = 0;
    }
    return 0;

}