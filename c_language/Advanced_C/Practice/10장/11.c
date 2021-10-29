#include <stdio.h>
#include <string.h>

int main(){
    char x[81], y[11];
    int len_x, len_y, check, total = 0;
    int tmp;

    scanf("%s", x);
    scanf("%s", y);

    len_x = strlen(x);
    len_y = strlen(y);

    printf("%d ", len_x); // ¼öÁ¤

    for(int i = 0; i < len_x - len_y + 1; i++) {
        check = 0;
       
        
        for(int j = 0; j < len_y; j++) {
            // printf("i = %d j = %d 1 = %c 2 = %c\n", i, j, x[i + j], y[j]);
            // printf("stop");
            // scanf("%d", &tmp);
            // printf("\n");
        
            if(x[i + j] == y[j]){
                check++;
            }
        }
        if(check == len_y){
            break;
        }
    }
    if(check == len_y){
        printf("1");
    }
    else{
        printf("0");
    }


    return 0;
}