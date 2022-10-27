#include <stdio.h>

int main(){
    char str[20];

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        if('a' <= str[i] && str[i] <= 'z'){
            printf("%c", str[i]);
        }
    }

    return 0;
}