#include <stdio.h>

int main(){
    int arr[10];
    int i, total = 0;
    for(i = 0; i < sizeof(arr)/sizeof(int); i++){
        scanf("%d", &arr[i]);
        total += arr[i];
    }
    printf("%d", total);

    return 0;
}