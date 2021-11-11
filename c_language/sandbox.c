#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **str;

    for(int i = 0; i < 2; i++){
        scanf("%s", *(str + i));
        getchar();
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < strlen(*(str + i)); j++){
            printf("%s\n", (*(str + i) + j));
        }
    }


    return 0;
}