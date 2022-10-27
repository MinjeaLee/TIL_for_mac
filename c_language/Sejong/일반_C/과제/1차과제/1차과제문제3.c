#include <stdio.h>

int main(){
    int num_1, num_2, num_3; // 입력 받은 세 개의 값들 저장할 변수 설정
    int hun_1, hun_2, hun_3; // 입력받은 값들의 백의 자리수 저장할 변수 설정
    char result;    // 결과값을 저장할 변수 설정
    scanf("%d %d %d", &num_1, &num_2, &num_3); // 값 입력
    hun_1 = num_1 / 100; // 백의 자리수를 추출
    hun_2 = num_2 / 100;
    hun_3= num_3 / 100;
    // 세개의 조건식을 가지고 조건 연산자를 이용, 결과 값에 결과 저장.
    // 먼저 백의 자리 수가 모두 같다면 T, 아니면 D를 저장 한 후
    // 백의 자리수가 두개 같다면 전 조건식의 결과값을 저장, 아니면 S를 저장 
    result = hun_1 == hun_2 || hun_2 == hun_3 || hun_3 == hun_1 ? (hun_1 == hun_2 && hun_2 == hun_3 ? 'T' : 'D') : 'S';
    printf("%c", result); // 결과 출력
    return 0;
}