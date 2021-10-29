#include <stdio.h>
#include <string.h>

int main(){
    int n, len, min_len = 10000;
    char str[101], min_str[101];

    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++) {
        gets(str);
        len = strlen(str);
        if(len < min_len) {
            min_len = len;
            strcpy(min_str, str);
        }
    }
    
    printf("%s", min_str);



    return 0;
}