#include <stdio.h>

int main(){
    int n, arr[100];
    int *p;

    scanf("%d", &n);
    for(p = arr; p < arr + 10; p++){
        scanf("%d", p);
    }
    for(p =arr; p < arr + n; p++){
        printf("%d ", *p);
    }

    return 0;
}