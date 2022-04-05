#include <stdio.h>

int main(){
    char ch, result;

    scanf("%c", &ch);

    if('a' <= ch && ch <= 'z'){
        printf("영어\n");
        ch = ch - 'a';
        result = 'A' + ch;
        printf("%c", result);
    }
    else if('A' <= ch && ch <= 'Z'){
        printf("영어\n");
        ch = ch - 'A';
        result = 'a' + ch;
        printf("%c", result);
    }
    else{
        printf("숫자");
    }

    return 0;
}