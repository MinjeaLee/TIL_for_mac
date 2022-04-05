#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strrev_1(char* str){
    int startIdx, endIdx;
    if(!str || !*str)    return (char *)-1;
    startIdx = 0;
    endIdx = strlen(str)-1;
    while(startIdx<endIdx) {
        char tmp = str[startIdx];
        str[startIdx] = str[endIdx];
        str[endIdx] = tmp;
        startIdx ++;
        endIdx --;
    }
    return str;
} 

int main(){
    int n, space_check = 0, len, min = 101, max = -1;
    char str[101], *p, *max_str, *min_str, *p_2;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        gets(str);
        len = 0;
        for(p = str; *p != '\0'; p++){
            if(*p != ' '){
                space_check = 0;
            }
            if(*p == ' '){
                space_check = 1;
            }

            if(space_check == 0){
                len++;
            }
            if(space_check == 1){
                if(len > max){
                    max = len;
                    max_str = malloc(len + 1);
                    for(p_2 = p; p_2 > p - len; p_2--, max_str++){
                        *max_str = *p_2;
                    }
                }
                if(len < min){
                    min = len;
                    min_str = malloc(len + 1);
                    for(p_2 = p; p > p - len; p_2--, min_str++){
                        *min_str = *p_2;
                    }
                }
                
            }
        }
    }
    strrev_1(min_str);
    strrev_1(max_str);
    printf("%s\n%s",min_str, max_str);

    free(min_str);
    free(max_str);

    return 0;
}