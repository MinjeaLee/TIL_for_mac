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
    char x[1001], y[1001], operator, str_result[1002], tmp;
    int len, carry = 0, sum = 0, sub = 0;

    scanf("%s %c %s", x, &operator, y);

    strrev_1(x);
    strrev_1(y);

    len = strlen(x) > strlen(y) ? strlen(x) : strlen(y);

    if(operator == '+'){
        for(int i = 0; i < len; i++){
            sum = x[i] - '0' + y[i] - '0' + carry;
            while(sum < 0) sum += '0';
            if(sum > 9) carry = 1;
            else carry = 0;
            str_result[i] = sum % 10 + '0';
        }
        if(carry == 1) str_result[len] = '1';
        strrev_1(str_result);
    }
    else{
        carry = 0;
        for(int i = 0; i < len; i++){
            sub = (x[i] - '0') - (y[i] - '0') + carry;
            if(sub < 0){
                carry = -1;
                sub += 10;
            }
            else{
                carry = 0;
            }
            
            str_result[i] = sub % 10 +'0';
        }
        // if(carry == -1){
        //     str_result[len - 1] = '\0';
        // }
        strrev_1(str_result);
    }


    printf("result : %s", str_result);

    return 0;
}