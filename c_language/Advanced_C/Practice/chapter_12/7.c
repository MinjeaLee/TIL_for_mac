#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **array;
    int height, width;
    char start = 'a';
    
    scanf("%d %d", &height, &width);
    array = (char **)malloc(sizeof(char *) * height);
    for(int i = 0; i < height; i++){
        array[i] = (char *)malloc(sizeof(char) * width);
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            array[i][j] = start;
            start++;
            if(start == 'z' + 1){
                start = 'A';
            }
            if(start == 'Z' + 1){
                start = 'a';
            }
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < height; i++){
        free(array[i]);
    }
    free(array);

    return 0;
}