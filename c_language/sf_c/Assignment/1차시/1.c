#include <stdio.h>
#include <math.h>
#include <string.h>

void append(char *dst, char c) {
    char *p = dst;
    while (*p != '\0') p++; // 문자열 끝 탐색
    *p = c;
    *(p+1) = '\0'; 
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
    int n, num, extra;

    scanf("%d", &n);

    num = pow(n, 2);
    extra = num / 9;
    num += extra;

    printf("%d\n", num % 10);
    for(int i = 1; i < n; i++){
        for(int j = num - (2 * i + 1); j < num; j++){
            if(num % 10 == 0){
                num--;
                j--;
            }
            printf("%d", j % 10);
        }
        printf("\n");
    }

    return 0;
}