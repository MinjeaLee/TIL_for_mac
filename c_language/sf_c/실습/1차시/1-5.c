#include <stdio.h>

int main(){
    char x[100];
    char *last, *p;

    scanf("%s", x);

    for(p = x; *p != '\0'; p++){
        last = p;
    }
    for(p = last; p >= x; p--){
        printf("%c", *p);
    }

    return 0;
}