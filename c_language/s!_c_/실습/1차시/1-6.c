#include <stdio.h>

int main(){
    char x[7];
    int num = 0;

    for(int i = 0; i < 7; i++){
        scanf("%c", &x[i]);
    }

    for(int i = 0; i < 5; i++){
        if(x[i] == 'c' && x[i + 1] == 'a' && x[i + 2] == 't'){
            num++;
        }
    }
    printf("%d", num);

    return 0;
}