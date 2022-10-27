// 1 ? (2 ? 1:2) : (3? 1:2)

#include <stdio.h>

int main(){
    int num_b, num_a, result;   // 처음 입력 받을 양수, 이를 뒤집은 수, 그 둘을 뺀 결과값 저장할 변수 선언
    int th, hun, ten, one;      // 입력받을 수의 천의 자리, 백의 자리, 십의 자리, 일의 자리를 저장할 변수 선언 
    scanf("%d", &num_b);        // 수 입력
    th = num_b / 1000;          //  입력받은 수의 천의 자리, 백의 자리, 십의 자리, 일의 자리를 각 변수에 저장 
    hun = num_b % 1000 / 100;
    ten = num_b % 100 / 10;
    one = num_b % 10;
    num_a = one * 1000 + ten * 100 + hun * 10 + th; // 각각의 자리수를 뒤집어서 변수에 저장
    result = num_a - num_b; // 처음 수와 나중 수(뒤집은 수)를 뺀 값을 결과값에 저장
    result = result > 0 ? result : -1 * result; // 결과값이 양수라면 그대로, 음수라면 -1를 곱한 값으로 저장
    printf("%d", result);   // 결과 값 출력

    return 0;
}