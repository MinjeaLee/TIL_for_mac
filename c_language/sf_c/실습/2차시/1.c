#include <stdio.h>

void change(char *x){
    int dif;
    if('a' <= *x && *x <= 'z'){
        dif = *x - 'a';
        *x = 'A' + dif;
    }
    else{
        dif = *x - 'A';
        *x = 'a' + dif;
    }
}

int main(){
    char ch1 = 'A', ch2 = 'b';
    char *ptr1 = &ch1, *ptr2 = &ch2;

    change(ptr1);
    change(ptr2);

    printf("%c %c", *ptr1, *ptr2);

    return 0;
}