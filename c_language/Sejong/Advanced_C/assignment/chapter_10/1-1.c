#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char str[21], num_char[3], result[1024];    // 입력받을 문자열 저장, 문자열에 나오는 문자형의 숫자를 저장, 변환 결과 저장하기 위한 문자열 선언
    int n, num_int;                             // n, 문자형의 숫자를 정수형으로 저장할 변수 선언
    char *p_str, *p_result;                     // 문자열 포인터 선언

    gets(str);                                  // 문자열 입력
    scanf("%d", &n);                            // n 입력
    

    p_result = result;                          // 포인터 연결
    for(p_str = str; *p_str != '\0'; p_str++, p_result++){      // 입력 받은 문자열 탐색, 결과 문자열 포인터 1씩 더해나감
        if('A' <= *p_str && *p_str <= 'Z'){                     // 대문자 경우
            *p_str += n;                                        // n만큼 더해준 뒤 결과에 저장
            *p_result = *p_str;
        }
        else if('a' <= *p_str && *p_str <= 'z'){                // 소문자 경우
            *p_str -= n;                                        // n만큼 빼준 뒤 결과에 저장
            *p_result = *p_str;
        }
            
        else if('0' <= *p_str && *p_str <= '9'){                //  숫자의 경우
            if('0' <= *(p_str + 1)&& *(p_str + 1)<= '9'){       // 숫자가 연속 해서 나온 경우 즉, 두자리의 숫자의 경우
                num_char[0] = *p_str;                           // 첫번째 숫자 -> 10의 자리 숫자 0번째 문자형 숫자 문자열에 저장
                num_char[1] = *(p_str+1);                       // 두번째 숫자 -> 1의 자리 숫자 1번째 문자형 숫자 문자열에 저장
                num_char[2] = '\0';                             // null문자 삽입
                p_str++;                                        // 문자열 탐색 인덱스를 1 더해줘 다음 문자(1의 자리 숫자)를 건너뛰게 함
            }
            else{                                               // 숫자가 하나인 경우, 1의 자리 숫자만 있는 경우
                num_char[0] = *p_str;                           // 위와 동일한 방법으로 문자열에 저장
                num_char[1] = '\0';
            }
            num_int = atoi(num_char);                           // 정수형으로 변환
            for(int i = 0; i < n; i++, p_result++){             // n만큼 반복, 결과값도 반복하여 증가
                *p_result = 'A' + num_int - 1;                  // 숫자 만큼의 문자 저장
            }
            p_result--;                                         // 결과 인덱스가 추가로 더해지므로 -1
        }
        else{
            *p_result = ' ';                                    // 소문자, 대문자, 숫자가 아닌경우 ' '삽입
        }
    }
    *(p_result + 1) = '\0';                                     // 결과 문자열의 마지막 인덱스에 null문자를 삽입


    printf("%s", result);                                       // 결과 출력

    return 0;
}