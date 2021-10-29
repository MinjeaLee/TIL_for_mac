#include <stdio.h>

void strcpy(char a[], char b[]){
    char *p_b, *p_a;

    p_a = a;

    for(p_b = b; p_b < b + 6; p_b++){
        *p_a = *p_b;
        p_a++;
    }
}

int main(){
    char x[6], y[6];
    char *p_x;

    for(p_x = y; p_x < y + 6; p_x++){
        scanf("%c", p_x);
    }

    strcpy(x, y);

    for(p_x = x; p_x < x + 6; p_x++){
        printf("%c", *p_x);
    }


    return 0;
}