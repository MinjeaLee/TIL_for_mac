#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int a[] = {3, 4, 5, 6, 1, 2};
    int max = -1;

    for(int i = 0; i < 6; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    printf("%d\n", max);


    return 0;
}