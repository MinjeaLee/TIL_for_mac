#include <stdio.h>

int add(int x, int y){
    return x + y;
}

int main(){
    int n, sum = 0, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        sum = add(sum, i);
    }
    printf("%d", sum);

    return 0;
}