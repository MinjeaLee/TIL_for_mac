#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// find the maximum 1 row in the beat table
// time = O(n)

int find_max_row(int table[][100], int len){
    int i = 0, j = 0, row = 0;

    while ((i < len) && (j < len)){
        if (table[i][j] == 0){
            i++;
        }
        else{
            row = i;
            j++;
        }
    }
    return row;
}

int main(){
    int table[100][100];
    int len;

    scanf("%d", &len);

    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            scanf("%d", &table[i][j]);
        }
    }

    printf("%d\n", find_max_row(table, len));

    return 0;
}