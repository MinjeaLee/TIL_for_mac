#include <stdio.h>

int main(){
    char str[100];
    char tmp;
    int len = 0;

    scanf("%s", str);

    
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }

    printf("%s\n", str);
    for(int i = 0; i < len - 1; i++){
        tmp = str[0];
        for(int j = 0; j < len - 1; j++){
            str[j] = str[j+1];
        }
        str[len - 1] = tmp;

        printf("%s\n", str);
    }

    return 0;
}