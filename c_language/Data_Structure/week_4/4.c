#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int arr[100][100] = {0, };
    int n, m;
    scanf("%d %d", &n, &m);
    int i = 0, j = 0, a = 1;


    i = 0;
    j = 0;
    arr[i][j] = 1;
    a = 2;

    while (a <= n * m){

        while (j + 1 < m && arr[i][j + 1] == 0){
            j++;
            arr[i][j] = a;
            a++;
        }

        while (i + 1 < n && arr[i + 1][j] == 0){
            i++;
            arr[i][j] = a;
            a++;
        }

        while (j - 1 >= 0 && arr[i][j - 1] == 0){
            j--;
            arr[i][j] = a;
            a++;
        }
        while (i - 1 >= 0 && arr[i - 1][j] == 0){
            i--;
            arr[i][j] = a;
            a++;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}
