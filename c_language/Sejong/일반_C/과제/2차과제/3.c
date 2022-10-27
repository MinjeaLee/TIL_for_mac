#include <stdio.h>

int main(){
    int num1, num2, result;
    // 입력받을 정수 a,b,c를 각각 num1, num2, result로 선언
    scanf("%d %d %d", &num1, &num2, &result);
    // 세 정수 입력
    if(num1 + num2 == result){
        // result가 num1과 num2가 +연산으로 이루어져 있다면 +출력
        printf("+\n");
    }
    if(num1 - num2 == result){
        // result가 num1과 num2가 -연산으로 이루어져 있다면 -출력
        printf("-\n");
    }
    if(num1 * num2 == result){
        // result가 num1과 num2가 *연산으로 이루어져 있다면 *출력
        printf("*\n");
    }
    if(num1 / num2 == result){
        // result가 num1과 num2가 -연산으로 이루어져 있다면 -출력
        printf("/\n");
    }
    if(num1 + num2 != result && num1 - num2 != result && num1 / num2 != result && num1 * num2 != result ){
        // result가 num1과 num2의 어느 계산예도 참이 아니라면 Incorrect출력
        printf("Incorrect\n");
    }
    return 0;
}