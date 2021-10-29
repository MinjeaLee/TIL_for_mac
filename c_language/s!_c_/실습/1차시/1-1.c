#include <stdio.h>

int main(){
    char ch, result;

    scanf("%c", &ch);

    ch = ch - 'A';
    result = 'a' + ch;

    printf("%c", result);

    return 0;
}