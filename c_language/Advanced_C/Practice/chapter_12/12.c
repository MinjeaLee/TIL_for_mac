#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    char **arr, str[101], *tmp;
    int str_len;

    scanf("%d",&n);
    getchar();
    arr = (char **)malloc(n * sizeof(char*));
    for(int i=0; i<n; i++){
        scanf("%s", str);
        str_len = strlen(str);
        arr[i] = (char *)malloc(str_len * sizeof(char));
        strcpy(arr[i], str);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(arr[j], arr[i]) < 0){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s", arr[i]);
    }
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);


    return 0;
}