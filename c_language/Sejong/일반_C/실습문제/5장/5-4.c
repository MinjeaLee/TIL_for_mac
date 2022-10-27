#include <stdio.h>

int main(){
    char eng, result;
    
    scanf("%c", &eng);
    if ('A'<= eng && eng <= 'Z'){
        result = 'a' + (eng - 'A');
        printf("%c", result);
    }
    else if('a' <= eng && eng <= 'z'){
        result = 'A' + (eng - 'a');
        printf("%c", result);
    }
    else{
        printf("none");
    }
    return 0;
}