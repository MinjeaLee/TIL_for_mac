#include <stdio.h>

int main(){
    int num, tmp, one_num,count = 0;
    char result_str[10];
    char ch_tmp;

    scanf("%d", &num);

    tmp = num;

    while(tmp > 0){
        count++;
        tmp /= 10;
    }

    result_str[count] = '\0';

    for(int i = 0; num > 0; i++){
        one_num = num % 10;
        num /= 10;
        ch_tmp = '0' + one_num;
        result_str[i] = ch_tmp;
    }

    printf("%s", result_str);

    return 0;
}