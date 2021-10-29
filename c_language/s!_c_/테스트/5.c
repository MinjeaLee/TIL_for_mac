#include <stdio.h>
#include <string.h>

int main(){
    char str[1000000];
    char *p;
    int ing = 0, word = 0;


    scanf("%s", str);

    for(p = str; p < str + (int)strlen(str) - 1; p++){
    
        if(*p == '-' && *(p + 1) != '-'){
            ing = 1;
            word++;
        }
        
    }
    if(*str != '-'){
        word++;
    }

    printf("%d", word);

    return 0;
}