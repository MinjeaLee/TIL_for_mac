#include <stdio.h>
#include <string.h>

int s_check(char *p, char *q){
    int total = 0;              // 결과 담을 변수 선언
    char *p_str;                // 포인터 선언
    for(p_str = p; p_str <= q; p_str++){        // 시작점부터 종점까지 탐색
        if('a' <= *p_str && *p_str <= 'z'){     // 소문자인 경우
            total++;                            // total ++
        }
    }

    return total;   // 결과 반환
}

int main(){
    int k1, k2, m;      // k1, k2, m 변수 선언
    char str[201];      // 문자열 선언

    scanf("%d\n%d %d", &m, &k1, &k2);       // k1, k2, m 선언
    getchar();  // 엔터 getchar()

    for(int i = 0; i < m; i++){     // m 만큼 반복
        gets(str);          // 문자열 입력
        if(strlen(str) < k2){           // k2 값이 문자열 길의 값 보다 큰경우
            if(s_check(str + k1, str + strlen(str) -1)){    // 시작점과 문자열 끝을 매개변수로 함수 호출 -> 0이 아닌 경우
                printf("%d\n", s_check(str + k1, str + strlen(str) -1));    // 결과 출력
            }
        }
        else{           // k2값이 문자열길이보다 작은 경우
            if(s_check(str + k1, str + k2)){        // 시작점 주소와 종점 주소를 매개변수로 함수 호출 -> 0이 아닌경우
                printf("%d\n", s_check(str + k1, str + k2));        // 결과값 출력
            }
        }
    }
    return 0;
}