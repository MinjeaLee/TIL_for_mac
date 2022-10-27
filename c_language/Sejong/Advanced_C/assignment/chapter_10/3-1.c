#include <stdio.h>
#include <string.h>

int main(){
    char x[101], y[101];        // 두 문자열 선언
    int len_x, len_y, check, total = 0;     // 문자열 길이, 같은 문자를 카운트, 몇번 반복되는 지 저장할 변수 선언

    gets(x);        // 문자열 입력
    gets(y);
    
    len_x = strlen(x);      // 문자열 길이 저장
    len_y = strlen(y);

    for(int i = 0; i < len_x - len_y + 1; i++){     // x 문자열의 길이 - y 길이 문자열 + 1만큼 반복, x문자열에서 y문자열의 길이를 뺀만큼반복하여 x문자열을 탐색 할 것이기 때문
        if(x[i] == *y){         // y문자열의 첫번째 문자가 나왔을때
            check = 0;          // 체크를 0으로 초기화
            for(int j = 0; j < len_y; j++){     // y 문자열만큼 반복 ->앞선 for문에서의 조건(x 문자열의 길이 - y 길이 문자열 + 1만큼 반복)의 이유
                if(x[i + j] == y[j]){           // x, y문자열 비교
                    check++;                // check++
                }
            }
            if(check == len_y){ // 겹치는 문자가 y의 문자열의 길이일때 -> 동일한 경우
                total++;        // total++
                i = i + len_y - 1;  // i를 i + y문자열 길이 - 1해주어 반복으로 체크되는 경우 방지
            }
        }
    }

    printf("%d", total);        // 결과 출력

    return 0;
}