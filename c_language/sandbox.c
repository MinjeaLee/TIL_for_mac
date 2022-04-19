#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, m;
    char chess_board[50][50];

    int count = 0;
    int max_count = -1;
    int max_1d_index, max_2d_index;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &chess_board[i][j]);
        }
    }

    for(int i = 0; i < n - 8; i++){
        for(int j = 0; j < m - 8; j++){
            
        }
    }



    return 0;
}