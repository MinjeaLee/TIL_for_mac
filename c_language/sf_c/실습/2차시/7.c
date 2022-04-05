#include <stdio.h>

int len(char x[]){
    int len = 0;

    for(int i = 0; x[i] != '\0'; i++){
        len++;
    }

    return len;
}

void swap(char *x, char *y){
    char tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    char str_1[41], str_2[21];
    int len_1, len_2, index;

    scanf("%s\n%s\n%d", str_1, str_2, &index);

    len_1 = len(str_1);
    len_2 = len(str_2);

    for(int i = 0; i < len_1 - index; i++){
        swap(str_1 + (len_1 - 1 - i),str_1 + (len_1 + len_2 - 1 - i));
    }
    for(int i = 0; i < len_2; i++){
        swap(str_2 + i, str_1 + index + i);
    }

    str_1[len_1 + len_2] = '\0';

    printf("%s", str_1);

    return 0;
}