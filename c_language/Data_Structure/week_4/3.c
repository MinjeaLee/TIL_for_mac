#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int arr[100][100];
    int n;
    int num = 1;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            for(int j=0; j<n; j++){
                arr[i][j] = num;
                num++;
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                arr[i][j] = num;
                num++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}