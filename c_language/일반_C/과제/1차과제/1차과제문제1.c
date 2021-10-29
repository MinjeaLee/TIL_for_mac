#include <stdio.h>

int main(){
    int result, num;    // 어떤 수의 배수인지를 저장할 변수와, 입력받는 수를 저장할 변수를 선언
    scanf("%d", &num);  // 정수 입력
    result = num;       
    // 우선적으로 결과값을 입력받은 수로 해놓아 아래의 조건들에 모두 거짓일 경우 입력 받은 수를 결과값으로 저장하도록 함.
    result = (num % 3 == 0) && (num % 5 == 0) ? 15 : result;
    // 3과 5가 공배수일 경우 15의 배수로 결과 값에 저장
    result = (num % 3 == 0) && !(num % 5 == 0) ? 3 : result;
    // 3의 배수 이지만 5의 배수가 아닐경우 3의 배수로 결과 값에 저장
    result = !(num % 3 == 0) && (num % 5 == 0) ? 5 : result;
    // 3의 배수가 아니지만 5의 배수 일경우 5의 배수로 결과 값에 저장
    printf("%d is a multiple of %d.", num, result);
    // 입력받은 수와 결과 값을 차례대로 출력.

    return 0;
}