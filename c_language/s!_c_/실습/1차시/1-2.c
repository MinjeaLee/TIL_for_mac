#include <stdio.h>

int main(){
    char ch, result;

    scanf("%c", &ch);

    if('a' <= ch && ch <= 'z'){
        printf("����\n");
        ch = ch - 'a';
        result = 'A' + ch;
        printf("%c", result);
    }
    else if('A' <= ch && ch <= 'Z'){
        printf("����\n");
        ch = ch - 'A';
        result = 'a' + ch;
        printf("%c", result);
    }
    else{
        printf("����");
    }

    return 0;
}