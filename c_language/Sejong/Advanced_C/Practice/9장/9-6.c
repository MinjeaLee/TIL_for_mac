#include <stdio.h>

int main(){
    char string[10], max_count_char;
    char *p_s, *p_s2;
    int max_count = 0, count = 0;

    for(p_s = string; p_s < string + 10; p_s++){
        scanf("%c", p_s);
    }

    for(p_s = string; p_s < string + 10; p_s++){
        for(p_s2 = string; p_s2 < string + 10; p_s2++){
            if(*p_s == *p_s2){
                count++;
            }
        }
        if(count > max_count){
            max_count = count;
            max_count_char = *p_s;
        }
        count = 0;
    }

    printf("%c %d", max_count_char, max_count);

    return 0;
}