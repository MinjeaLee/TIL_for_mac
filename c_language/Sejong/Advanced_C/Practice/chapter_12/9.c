#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **str, tmp_str[101], *tmp_pnt;
    int n, len_str;

    scanf("%d", &n);
    getchar();

    str = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; i++){
        gets(tmp_str);
        len_str = strlen(tmp_str);
        str[i] = (char *)malloc(sizeof(char) * len_str);
        strcpy(str[i], tmp_str);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strlen(str[i]) < strlen(str[j])){
                tmp_pnt = str[i];
                str[i] = str[j];
                str[j] = tmp_pnt;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s\n", str[i]);
    }
    for(int i = 0; i < n; i++){
        free(str[i]);
    }
    free(str);

    return 0;
}