#include <stdio.h>
#include <string.h>

int main(){
    char word[101], tmp;    // 문자열, tmp 선언

    scanf("%s", word);      // 문자열 입력

    // 버블정렬 사용
    for(int i = 0; i < strlen(word) - 1; i++){
        // 차례대로 비교 문자 개수를 len - 1로 시작
        for(int j = 0; j < strlen(word) - 1 - i; j++){
            if(word[j] > word[j + 1]){ // 아스키코드가 큰값을 뒤로 보내기 위함
                tmp = word[j];      // 두 문자 스왑 과정
                word[j] = word[j + 1];
                word[j + 1] = tmp;
            }
        }
    }

    printf("%s", word);

    return 0;
}