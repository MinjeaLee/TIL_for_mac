#include <stdio.h>

int main(){
    char str[7];
    int i, count = 0;
    for(i = 0; i < 7; i ++){
        scanf("%c", &str[i]);
    }
    for(i = 0; i < 5; i++){
        if(str[i] == 'c' && str[i+1] == 'a' && str[i+2] == 't'){
            count++;
        }
    }
    printf("%d", count);

    return 0;
}