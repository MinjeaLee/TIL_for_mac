#include <stdio.h>
#include <string.h>

int main(){
    char x[101], y[101];
    int len_x, len_y, check, total = 0;

    gets(x);
    gets(y);
    
    len_x = strlen(x);
    len_y = strlen(y);

    for(int i = 0; i < len_x - len_y + 1; i++){
        if(x[i] == *y){
            check = 0;
            for(int j = 0; j < len_y; j++){
                if(x[i + j] == y[j]){
                    check++;
                }
            }
            if(check == len_y){
                total++;
                i = i + len_y - 1;
            }
        }
    }

    printf("%d", total);

    return 0;
}