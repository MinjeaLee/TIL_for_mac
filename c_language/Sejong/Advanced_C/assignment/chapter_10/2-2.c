#include <stdio.h>
#include <string.h>

int main(){
    char word[10][100], string[1024], *p, tmp[100];
    // 단어를 저장할 이중 배열, 입력받은 문자열, 포인터, 단어를 스왑할 때 쓰일 문자열 선언
    int word_index_1d = 0, word_index_2d = 0, num_word = 0;
    // 이중 배열의 인덱스를 표현할 변수, 단어의 개수를 표현할 변수
    
    gets(string);   // 문자열 입력

    for(p = string; *p != '\0'; p++){   // 문자열이 끝날 때까지 반복
        if(*p != ' '){  // 공백이 아니라면
            word[word_index_1d][word_index_2d] = *p; // 이중 배열에 저장
            word_index_2d++;    // 옆으로 이동
        }
        else{ // 공백이면
            word[word_index_1d][word_index_2d] = '\0'; // 단어의 끝에 널문자 삽입
            num_word++;                                 // 단어의 개수 ++
            word_index_1d++;                            // 밑으로 이동
            word_index_2d = 0;                          // 처음으로 이동
        }
    }
    num_word++;         // 마지막 단어는 ++이 안되기에 ++

    for(int i = 0; i < num_word; i++){  // 단어 출력
        puts(word[i]);
    }

    for(int i = 0; i < num_word - 1; i++){       // 버블정렬 사용 차례대로 비교 단어 개수를 단어개수 - 1로 시작
        for(int j = 0; j < num_word - 1 - i; j++){
            if(word[j][0] > word[j + 1][0]){        //  첫 알파벳 비교 아스키코드가 큰값을 뒤로 보내기 위함
                strcpy(tmp, word[j]);       // 스왑과정
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tmp);
            }
        }
    }

    for(int i = 0; i < num_word; i++){      // 단어 출력
        puts(word[i]);
    }


    return 0;
}