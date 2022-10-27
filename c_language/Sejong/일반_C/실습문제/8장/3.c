#include <stdio.h>

int sum(int x){
    int add = x * (x + 1) / 2;
    return add;
}

int main(){
    int a, result = 0, i;
    scanf("%d", &a);
    for(i = 1; i <= a; i++){
        result += sum(i);
    }
    printf("%d", result);

    return 0;
}