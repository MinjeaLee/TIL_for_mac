#include <stdio.h>

int main(){
    int arr[10];
    int i;
    for(i = 0; i < sizeof(arr)/sizeof(int); i++){
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0){
            printf(" %d", arr[i]);
        }
    }
    return 0;
}