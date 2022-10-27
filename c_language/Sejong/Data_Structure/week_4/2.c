#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int chage(int *arr, int num_inject, int destination){
    int next_num_inject;

    next_num_inject = *(arr + destination);
    *(arr + destination) = num_inject;

    return next_num_inject;
}


int main(){
    int arr[100], change[100];
    int n, change_num;
    int num_inject;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &change_num);
    for(int i = 0; i < change_num; i++){
        scanf("%d", &change[i]);
    }

    num_inject = arr[change[0]];

    for(int i = 0; i < change_num; i++){
        num_inject = chage(arr, num_inject, change[i]);
    }

    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }

    return 0;
}