#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StringAdd(char arr[], char ch, int index) {
    char* p;
    int len;

    len = strlen(arr);

    for (p = arr + len; p > arr + index; p--){
        *p = *(p - 1);
    }

    *(arr + index) = ch;
}

int Convertor(char x){
    int int_num = atoi(&x);

    return int_num;
}

int main(){
    char str[21] = {0, }, a, b;
    int len;

    scanf("%s", str);

    len = strlen(str);
    
    for(int i = 0; i < len - 1; i++){
        a = Convertor(str[i]);
        b = Convertor(str[i + 1]);
        if(a % 2 == 0 && b % 2 == 0){
            StringAdd(str, '*', i + 1);
            len++;
            i++;
        }
        else if(a % 2 == 1 && b % 2 == 1){
            StringAdd(str, '+', i + 1);
            len++;
            i++;
        }
        else{
            continue;
        }
    }

    printf("%s", str);

    return 0;
}