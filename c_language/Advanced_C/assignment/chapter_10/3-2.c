#include <stdio.h>
#include <string.h>

int main(){
    char word[50][50], string[101], *p, cmp[101];
    // 나오는 단어를 저장할 배열, 입력받을 문자열, 포인터 , 비교단어 배열 선언
    int total = 0, word_index_1d = 0, word_index_2d = 0;// 총 개수, 이중 배열의 인덱스를 표현할 변수

    gets(string);   // 문자열 입력
    gets(cmp);      // 비교 단어 입력

    for(p = string; *p != '\0'; p++){   // 문자열이 끝날 때까지 반복
        if(*p != ' ' && *p != '.'){ // 공백이 아니고 . 이 아니라면
            word[word_index_1d][word_index_2d] = *p;// 이중 배열에 저장
            word_index_2d++;  // 옆으로 이동
        }
        else{ // 공백이거나 . 이라면
            word[word_index_1d][word_index_2d] = '\0';// 단어의 끝에 널문자 삽입
            word_index_1d++;// 밑으로 이동
            word_index_2d = 0; // 처음으로 이동
        }
    }

    for(int i = 0; i < word_index_1d + 1; i++){ // 단어의 개수 만큼 반복, 문자열 마지막이 공백이나 .이 아닌경우 갯수가 -1 되기때문에 +1 해줌
        if(strcmp(word[i], cmp) == 0){  // 단어가 같은경우
            total++; // 같은 개수 ++
        }
    }
    
    printf("%d", total);        // 결과 출력

    return 0;
}