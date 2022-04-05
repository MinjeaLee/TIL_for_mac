#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int **arr;
    int i, j, k;
    int m_x, m_y;
    int sign = 1, num = 1, x, y;

    scanf("%d", &size);
    if(size % 2 == 0){
        printf("Invalid number");
        return 0;
    }

    m_x = (size - 1) / 2;
    m_y = m_x;
    x = m_x;
    y = m_y;


    arr = (int**)malloc(sizeof(int*)*size);
    for(i = 0; i < size; i++){
        arr[i] = (int*)malloc(sizeof(int)*size);
    }

    arr[x][y] = num++;

    for(i = 1; i < size; i++){
        for(j = 0; j < i; ++j){
            x += sign;
            arr[y][x] = num++;
        }
        for(k = 0; k < i; ++k){
            y += sign;
            arr[y][x] = num++;
        }

        sign *= -1;
    }
    for(i = 0; i < size; i++){
        x += sign;
        arr[y][x] = num++;
    }

    for(i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<size; i++)
    {
        free(arr[i]);
    }
    free(arr);


    return 0;
}