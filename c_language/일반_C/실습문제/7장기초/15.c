#include <stdio.h>

int main(){
    char x[10];
    int i, j, check, len = sizeof(x) / sizeof(char);
    for(i = 0; i < len; i++){
        scanf("%c", &x[i]);
    }
    for(i = 0; i < len; i++){
        check = 0;
        for(j = 0; j < i; j++){
            if(x[i] == x[j]){
                check++;
                break;
            }
        }
        for(j = i + 1; j < len; j++){
            if(x[i] == x[j]){
                check++;
                break;
            }
        }
        if(check == 0){
            printf(" %c", x[i]);
        }
    }
    return 0;
}