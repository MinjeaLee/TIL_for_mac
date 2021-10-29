#include <stdio.h>

int main(){
    int len = 0, check = 1;
    char str_1[100], str_2[100];

    scanf("%s\n%s", str_1, str_2);

    for(int i = 0; str_1[i] != '\0'; i++){
        len++;
    }

    for(int i = 0; i < len; i++){
        if(str_1[i] != str_2[i]){
            check = 0;
            break;
        }
    }

    printf("%d %d", len, check);

    return 0;
}