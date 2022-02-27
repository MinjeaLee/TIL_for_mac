// 입력된 단어를 알파벳순으로 정렬하는 프로그램을 작성하시오.
// 1개의 단어와 해당 단어는 소문자로만 입력된다고 가정한다.
// 입력 받은 단어를 저장하는 문자 배열을 제외하고 정렬을 위한 별도의 문자 배열을 사용하지 않는다.
// 문자열의 최대길이는 (널 문자 포함하여) 100 이다.
// 입력 예시 1 : guest
// 출력 예시 1 : egstu

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[100];
    char result[100];
    int i, j, k, len;
    char temp;

    scanf("%s", str);
    len = strlen(str);

    for(i=0; i<len - 1; i++){
        for(j=0; j<len - 1 - i; j++){
            if(str[j] > str[j+1]){
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }

    printf("%s", str);
    

    return 0;
    
}