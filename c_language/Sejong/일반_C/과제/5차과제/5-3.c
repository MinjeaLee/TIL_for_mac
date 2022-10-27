#include <stdio.h>
//restore github
#include <limits.h>         // 최솟값에 int가 가질 수 있는 최솟값으로 저장하게하기 위해 limits.h를 포함시킴

int add_digits(int n){      // add_digit함수 정의
    int result = 0, num;    // 결과값 저장 변수, 각 자릿수 저장 변수 선언
    if(n == 0){             // n이 0일 경우 밑의 while 문의 조건 때문에 들어가지 못하므로 따로 지정해줌 ->result = 0
        result = 0;
    }
    while(n != 0){          // n이 0일 경우
        num = n % 10;       // num은 n의 일의 자리
        result += num;      // result값에 num을 +  
        n /= 10;            // n을 n / 10으로
    }
    return result;          // reuslt 값을 반환
}

int len_check(int x){       // 숫자의 길이를 알 필요가 있어 len_check함수 정의
    int len = 0;            // len을 0으로 선언
    if(x == 0){             // x가 0일 경우 밑의 while문에 못들어가므로 len을 1로 설정
        len = 1;
    }
    while(x != 0){          // x가 0일 경우
        len++;              // len++
        x /= 10;            // x를 x / 10으로 저장
    }
    return len;             // len 을 반환
}

int main(){
    int num, len, num_check,min = INT_MAX, min_num;     // 입력받을 숫자, 숫자의 길이, 입력받을 숫자를 저장할 변수 선언, 최솟값을 int가 가질 수 있는 최솟값으로 선언, 최솟값일때의 num을 저장할 변수 선언
    while(1){                                       // 무한루프
        scanf("%d", &num);                          // 숫자 입력
        if(num < 0){                                // 숫자가 음수 일때 break
            break;
        }
        num_check = num;                            // num_check를 num으로  설정
        len = len_check(num_check);                 // len 저장
        while(len != 1){                            // len이 1일 아닐때까지 반복
            num_check = add_digits(num_check);      // num_check는 add_digits(num_check)의 결과값을 저장
            len = len_check(num_check);             // num_check의 길이를 len으로 저장
        }
        if(num_check < min){                        // num_check 가 min보다 작을 때
            min = num_check;                        // 최솟값을 num_check로 저장
            min_num = num;                          // 최소일때의 숫자를 num으로 설정
        }
    }

    printf("%d %d", min_num, min);                  // 차례대로 설정

    return 0;
}
