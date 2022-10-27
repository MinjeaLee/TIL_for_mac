#include <stdio.h>
//restore github

int is_prime_number(int num){       // is_prime_number 함수 정의
    int check = 1;                  // 소수인지 아닌지를 판단할 변수를 1로 선언
    for(int i = 2; i < num; i++){   // 소수인지 판단 하기위해 2부터 num - 1까지 i를 1씩 증가시키며
        if(num % i == 0){           // num이 i의 배수라면 소수가 아니므로
            check = 0;              // check 를 0으로 저장하고 break
            break;
        }
    }
    return check;                   // check를 반환
}

int main(){
    int n, number, lim, i, count = 0;       // 횟수, 입력 받을 수, 출력할 소수의 개수, for문 변수, 소수의 개수를 저장할 변수 선언
    scanf("%d %d", &n, &lim);               // 회수와 출력할 소수의 개수를 입력
    for(i = 0; i < n; i++){                 // n번 반복
        scanf("%d", &number);               // 숫자 입력
        if(is_prime_number(number) && count < lim && number != 1){      // 소수이고 지금까지의 출력한 소수의 개수가 출력할 소수의 개수보다 작으며, 숫자가 1이 아닌경우에만
            printf(" %d", number);          // 숫자 출력
            count++;                        // 지금까지 출력한 소수의 개수++
        }
    }
    if(count == 0){                         // 출력한 소수가 없다면
        printf("0");                        // 0 출력
    }

    return 0;
}