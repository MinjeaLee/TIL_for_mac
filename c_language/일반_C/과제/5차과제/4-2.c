#include <stdio.h>
//restore github

int is_prime_number(int num){       // is_prime_number 함수 정의
    int check = 1;                  // 소수인지 아닌지를 판단할 변수를 1로 선언
    if(num == 1){                   // 1은 소수가 아니므로
        check = 0;                  // check를 0으로
    }
    for(int i = 2; i < num; i++){   // 소수인지 판단 하기위해 2부터 num - 1까지 i를 1씩 증가시키며
        if(num % i == 0){           // num이 i의 배수라면 소수가 아니므로
            check = 0;              // check 를 0으로 저장하고 break
            break;
        }
    }
    return check;                   // check를 반환
}

int count_prime_number(int cnt, int num){           // count_prime_number 함수 정의 
    if(is_prime_number(num) && num < 100){          // 소수이면서 num이 100보다 작을때
        return cnt + 1;                             // cnt+1을 반환
    }
    else{                                           // 이외에는 
        return 0;                                   // 0 반환
    }
}

int main(){
    int n, num, i, last_num, count = 0, max_count = 0;      // 횟수, 숫자, for문변수, 마지막 숫자 저장 변수,구간 길이 저장 변수, 최대 길이 저장 변수 선언
    scanf("%d", &n);                                        // 횟수 입력
    for(i = 0; i < n; i++){                                 // 횟수만큼 반복
        scanf("%d", &num);                                  // 숫자 입력
        count = count_prime_number(count, num);             // count는 count_prime_number함수를 사용 하여 저장
        if(max_count < count){                              // max_count가 count보다 작으면
            max_count = count;                              // 그때의 count를 max_count로 저장
            last_num = num;                                 // 그때의 num을 last_num으로 저장
        }
    }
    if(max_count == 0){                                     // max_count가 0이면
        printf("0");                                        // 0 출력
    }
    else{                                                   // 이외에는
        printf("%d\n", max_count);                          // max_count, last_num을 차례대로 출력
        printf("%d", last_num);
    }
}