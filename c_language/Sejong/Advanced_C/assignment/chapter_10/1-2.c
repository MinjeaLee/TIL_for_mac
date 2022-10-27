#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *check(char *str, int n){   // 1-1번과 동일한 방법을 사용하기 위해 함수로 빼줌
    char num_char[3], result[41], check_string[21];    // 문자열에 나오는 문자형의 숫자를 저장, 변환 결과 저장하기 위한 문자열 선언, 변수로 받은 문자열을 가공하기위한 문자열 선언    
    int num_int; // n, 문자형의 숫자를 정수형으로 저장할 변수 선언
    char *p_str, *p_result, *p_final;   // 문자열 포인터 선언

    p_result = result;  // 포인터 연결
    strcpy(check_string, str);  // 매개변수 문자열을 가공하기 위해 기존 문자 복사
    for(p_str = check_string; *p_str != '\0'; p_str++, p_result++){ // 입력 받은 문자열 탐색, 결과 문자열 포인터 1씩 더해나감
        if('A' <= *p_str && *p_str <= 'Z'){// 대문자 경우
            *p_str += n;// n만큼 더해준 뒤 결과에 저장
            *p_result = *p_str;
        }
        else if('a' <= *p_str && *p_str <= 'z'){// 소문자 경우
            *p_str -= n;    // n만큼 빼준 뒤 결과에 저장
            *p_result = *p_str;
        }
        
        else if('0' <= *p_str && *p_str <= '9'){    //  숫자의 경우
            if('0' <= *(p_str + 1)&& *(p_str + 1)<= '9'){     // 숫자가 연속 해서 나온 경우 즉, 두자리의 숫자의 경우
                num_char[0] = *p_str;   // 첫번째 숫자 -> 10의 자리 숫자 0번째 문자형 숫자 
                num_char[1] = *(p_str+1);   // 두번째 숫자 -> 1의 자리 숫자 1번째 문자형 숫자 문자열에 저장
                num_char[2] = '\0'; // null문자 삽입
                p_str++;    // 문자열 탐색 인덱스를 1 더해줘 다음 문자(1의 자리 숫자)를 건너뛰게 함
            }
            else{   // 숫자가 하나인 경우, 1의 자리 숫자만 있는 경우
                num_char[0] = *p_str;   // 위와 동일한 방법으로 문자열에 저장
                num_char[1] = '\0';
            }
            num_int = atoi(num_char);   // 정수형으로 변환
            for(int i = 0; i < n; i++, p_result++){ // n만큼 반복, 결과값도 반복하여 증가
                *p_result = 'A' + num_int - 1;   // 숫자 만큼의 문자 저장
            }
            p_result--;     // 결과 인덱스가 추가로 더해지므로 -1
        }
        else{
            *p_result = ' ';    // 소문자, 대문자, 숫자가 아닌경우 ' '삽입
        }
    }
    *(p_result + 1) = '\0';     // 결과 문자열의 마지막 인덱스에 null문자를 삽입

    p_final = result;       // 결과 문자열 포인터 연결

    return p_final;         // 포인터 반환
}

int main(){
    char x[21], y[21];      // 두 문자열 선언
    int equal_check = 0, check_xy = 0;      // 가능을 체크할 변수, 1 OR 2를 출력할지 체크할 변수
    char *cmp;  // 비교 문자열 선언

    gets(x);      // 문자열 입력
    gets(y);

    for(int i = 1; i <= 10; i++){       // n이 1부터 10까지 이므로 반복
        cmp = check(x, i);          // 비교 문자열, x를 가공할 문자열 저장
        if(strcmp(y, cmp) == 0){       // 문자열 비교했을때 같으면
            equal_check++;              // 가능 체크 변수 ++
            check_xy = 1;               // a를 가공했을 때 b가 가능한 경우므로 1로 저장
            break;      // break
        }
    }
    
    for(int i = 1; i <= 10; i++){       // 위의 방식과 동일
        cmp = check(y, i);
        if(strcmp(x, cmp) == 0){
            equal_check++;
            check_xy = 2;           // b를 가공했을때 a가 가능한 경우므로 2 저장
            break;
        }
    }

    if(equal_check == 0){       // 가능한 경우가 없었다면
        printf("0");            // 0출력
    }   
    else{
        if(check_xy == 1){         //첫번째 경우이므로
            printf("1");            // 1출력
        }
        else{
            printf("2");            // 두 번째 경우이므로 2출력
        }
    }
    

    return 0;
}