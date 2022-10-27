#include <stdio.h>

int main(){
    char ch[10], max_char;
    char *ptr_ch, *x;
    int count, max_count = -1;

    for(ptr_ch = ch; ptr_ch < ch + 10; ptr_ch++){
        scanf("%c", ptr_ch);
    }
    for(ptr_ch = ch; ptr_ch < ch + 9; ptr_ch++){
        count = 0;
        for(x = ptr_ch + 1; x < ch + 10; x++){
            if(*ptr_ch == *x){
                count++;
            }
        }
        if(max_count < count){
            max_count = count;
            max_char = *ptr_ch;
        }
    }
    printf("%c %d", max_char, max_count + 1);

    return 0;
}