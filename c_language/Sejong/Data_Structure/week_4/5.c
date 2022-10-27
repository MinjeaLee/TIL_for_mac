#pragma warning(disable : 4996)
#include <stdio.h>

int main(){
    int arr[100][100] = {0, };
    int n, m;
    int i = 0, j = 0;
    int num = 1;
    int flag_i = 0, flag_j = 0;

    scanf("%d %d", &n, &m);

    arr[flag_i][flag_j] = 1;
    num = 1;

    while (flag_j + 1 < m && arr[flag_i][flag_j + 1] == 0){
        flag_j++; 
        num++;
        i = flag_i;
        j = flag_j;
        arr[i][j] = num;
        while (i + 1 < n && j - 1 >= 0 && arr[i + 1][j - 1] == 0){
            num++;
            arr[i + 1][j - 1] = num;
            i++;
            j--;
        }
    }

    while (flag_i + 1 < n && arr[flag_i + 1][flag_j] == 0){
        flag_i++;
        num++;
        i = flag_i;
        j = flag_j;
        arr[i][j] = num;

        while (i + 1 < n && j - 1 >= 0 && arr[i + 1][j - 1] == 0){
            num++;
            arr[i + 1][j - 1] = num;
            i++;
            j--;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}
