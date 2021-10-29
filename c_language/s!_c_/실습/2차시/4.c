#include <stdio.h>

int main(){
    int n, arr[100], count = 0;
    int *p;

    scanf("%d", &n);
    for(p = arr; p < arr +n; p++){
        scanf("%d", p);
    }
    for(p = arr; p < arr + n; p++){
        if(*p != 0){
            count++;
        }
        else{
            break;
        }
    }
    printf("%d", count);

    return 0;
}