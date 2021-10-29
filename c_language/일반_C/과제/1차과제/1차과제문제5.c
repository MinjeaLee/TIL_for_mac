#include <stdio.h>

int main(){
    int num, hun, ten, one, result;
    // 입력받을 정수, 정수의 백의 자리, 십의 자리, 일의 자리와 가장 큰 수를 저장할 변수 선언
    scanf("%d", &num); // 정수 입력

    hun = num / 100;        // 입력받은 수의 백의 자리, 십의 자리, 일의 자리를 각각의 변수에 저장
    ten = num % 100 / 10;
    one = num % 10;
    result = 0;     // 가장 큰 수를 우선적으로 최솟값인 0으로 초기화 

    result = (hun > ten) && (hun > one) ? hun : result; 
    // 백의 자리와 나머지 자리 수와 비교해 백의 자리가 크다면 결과값에 백의 자리를 저장
    result = (ten > hun) && (ten > one) ? ten : result;
    // 십의 자리와 나머지 자리 수와 비교해 십의 자리가 크다면 결과값에 십의 자리를 저장
    result = (one > ten) && (one > hun) ? one : result;
    // 일의 자리와 나머지 자리 수와 비교해 일의 자리가 크다면 결과값에 일의 자리를 저장

    printf("%d", result); // 결과값 출력

    return 0;
}