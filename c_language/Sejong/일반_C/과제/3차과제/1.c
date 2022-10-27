#include <stdio.h>

int main() {
    int total = 0, a, b, dif, i, tmp;
    // 숫자들을 계속해서 더할 변수 total, 첫 번째 숫자 저장 a, 두 번째 숫자 저장 b, 두 수의 차이 저장 dif, for문 변수 i, 스왑을 하기 위한 변수 tmp 선언

    scanf("%d %d", &a, &b);
    // 두수 입력
    if (a > b) { // a에 더 작은 수를 오게 하기 위해 a 가 b보다 더 클경우 스와을 해주는 과정
        tmp = a;
        a = b;
        b = tmp;
    }
    if ((a < 0 && b > 0)&& -a < b)  { // a만 음수 이고 둘의 절댓값이 b 가 더 클경우 예) -8 10
        dif = b + a;    // 두 수의 차이를 dif에 저장
        for (i = 0; i < dif; i++) { // 차이 만큼 반복
            total += b;     // total에 b를 하나씩 줄여가며 저장 예) 10 9
            b -= 1; 
        }
    }
    else if((a < 0 && b > 0)&& -a > b){   // a만 음수 이고 둘의 절댓값이 b 가 더 클경우 예) -72 4
        dif = b + a;    // 두 수의 차이를 dif에 저장
        for(i = 0; i < -dif; i++){  // 차이 만큼 반복
            total += a;     // total에 b를 하나씩 늘려가며 저장 예) -72 -71 ... -6 -5
            a += 1;
        }
    }
    else {  // 그 외의 경우 a에서 b까지 1씩 증가하며 더함.
        for (i = a; i <= b; i++) {
          total += i;
        }
    }
    printf("%d", total);    // 결과 출력.

    return 0;
}