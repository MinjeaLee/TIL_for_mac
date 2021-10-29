#include <stdio.h>

int main(){
    int max_word_len = -1, str_len = 0, word_len; // 가장 긴 단어의 길이 저장 -1로 초기화, 입력받는 문자열의 길이, 단어 길이 담을 변수 선언
    char str[100]; // 문자열 담을 배열 선언
    char *p_i, *p_j, *p_start = str, *p_end = str;
    //  포인터 변수 선언, 문자열을 훑어 보기위해 시작 주소와 끝주소를 저장할 포인터 변수 선언, 시작, 끝 포인터 변수는 일단 배열 시작 시점으로 초기화
    for(p_i = str; p_i < str + 100; p_i++){ // 문자열 입력 받기 위해 반복
        str_len++;  // 문자열의 길이를 ++
        scanf("%c", p_i);   // 문자 입력
        if(*p_i == '#'){    // 만약 #일경우
            break;  // 그만 입력
        }
    }
    while(p_end != str + str_len + 1){  // 끝 주소가 문자열 의 길이보다 작을 때까지
        word_len = 0;   // 단어의길이를 0으로 초기화
        for(p_i = p_start; 'a' <= *p_i && *p_i <= 'z'; p_i++){ // 시작 지점 부터 반복하고 소문자 일때 동안만 반복
            printf("%c", *p_i); // 문자 출력
            word_len++; // 단어 길이 ++
            p_end = p_i;    // 반복 시마다 끝 주소를 해당 주소로 초기화
            if(!('a' <= *(p_i + 1) && *(p_i + 1) <= 'z')){  // 다음 문자가 소문자가 아닐 때 줄바꿈 
                printf("\n");
            }
        }
        
        if(!('a' <= *p_start && *p_start <= 'z')){  // 소문자가 아니라면 끝주소를 ++
            p_end++;
        }
        
        if(word_len > max_word_len){        // 입력 받은 단어들의 최대 길이를 저장
            max_word_len = word_len;
        }
        p_start = p_end + 1;    // 시작 주소를 끝주소 다음 주소로 초기화
    }

    printf("%d", max_word_len);     // 최대 길이 출력

    return 0;
}