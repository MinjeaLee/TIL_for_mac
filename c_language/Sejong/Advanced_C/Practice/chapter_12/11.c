#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *arr, *newarr;
    int size = 5, print;


    arr = (int*)malloc(sizeof(int) * size);

    for(int i=0;;i++){
        scanf("%d",&arr[i]);
        if(arr[i] != -1){
            newarr = (int*)malloc(sizeof(int) * (size + 3));
            for(int j=0;j<size;j++){
                newarr[j] = arr[j];
            }
            free(arr);
            arr = newarr;
            size += 3;
        }
        else{
            print = i + 1;
            break;
        }
    }

    for(int i = 0; i < print; i++){
        printf(" %d",arr[i]);
    }
    

    return 0;
}