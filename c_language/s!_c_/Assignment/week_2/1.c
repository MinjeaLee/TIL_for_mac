#include <stdio.h>
#include <string.h>

void d_to_b(unsigned int d, char *b){
    while(1){
        *b = (d % 2) + '0';
        d = d / 2;
        b++;
        if(d == 0){
            break;
        }
    }
    *b = '\0';
}

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
    unsigned int decimal;
    char binary[1024];

    scanf("%d", &decimal);

    d_to_b(decimal, binary);

    strrev_1(binary);

    printf("%s", binary);

    return 0;
}