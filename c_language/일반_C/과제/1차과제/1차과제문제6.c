#include <stdio.h>

int main(){
    int a, b, c, result;
    // 입력 받을 세 개의 수를 정장할 변수, 중앙값을 저장할 변수 선언
    scanf("%d %d %d", &a, &b, &c);
    // 새 개의 수 입력
    result = 0;
    // 우선적으로 중앙값을 0으로 초기화
    result = (a > b && a < c) || (a < b && a > c) ? a : result;
    // a가 b보다 크고 c보다 작거나 a가 b보다 작고 c보다 클때 중앙값으로 a를 저장, 이외에는 중앙값을 그대로 저장
    result = (b > a && b < c) || (b < a && b > c) ? b : result;
    // b가 a보다 크고 c보다 작거나 b가 a보다 작고 c보다 클때 중앙값으로 b를 저장, 이외에는 중앙값을 그대로 저장
    result = (c > a && c < b) || (c < a && c > b) ? c : result;
    // c가 a보다 크고 b보다 작거나 c가 a보다 작고 b보다 클때 중앙값으로 c를 저장, 이외에는 중앙값을 그대로 저장

    printf("%d", result);
    // 중앙값 출력

    return 0;
}