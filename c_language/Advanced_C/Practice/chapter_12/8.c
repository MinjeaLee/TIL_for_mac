#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **str;
    int n, min_len = 101,min_len_index;

    scanf("%d",&n);
    getchar();
    
    str = (char **) malloc(n*sizeof(char*));

    for(int i = 0; i < n; i++){
        str[i] = (char *)malloc(sizeof(char) *101);
    }

    for(int i = 0; i < n; i++){
        gets(str[i]);
        
    }

    for(int i = 0; i < n; i++){
        if(min_len > strlen(str[i])){
            min_len = strlen(str[i]);
            min_len_index = i;
        }
    }

    printf("%s", str[min_len_index]);

    for(int i = 0; i < n; i++){
        free(str[i]);
    }
    free(str);
    

    return 0;
}