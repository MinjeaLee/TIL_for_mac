#include <stdio.h>

int main(){
    int num, len, len_check, i, num_check, pow, pow_add, result;
    // 입력 받을 수, 길이 카운트, 길이 체크할떄 쓰이는 변수 for문에 쓰이는 변수, 각각의 자리수, 자리수 추출할때 10제곱수, 결과값에 추가할때 쓰이는 10제곱수, 결과값
    pow = 1;    // 10 ^0
    pow_add = 1;    // 나중에 추가할 것이므로 우선 10^0
    result = 0; //결과값은 0으로 초기화
    len = 0;    // 길이도 0으로 초기화
    scanf("%d", &num);  // 수 입력
    len_check = num;    // 길이를 확인하기 위해 , num으로 해버리면 길이 체크하는 과정에서 처음값과 달리지기에 다른 변수에 저장
    do{
        len_check = len_check / 10; // 변수 / 10한 것을 다시 변수에 저장
        len++;  // len 카운트 +1
    } while(len_check != 0);    // 변수가 0이 아닐때 까지
    
    for(i = 0; i < len; i++){    // 길이 만큼 반복
        pow_add *= 10;  // 처음수를 역순으로 더할때는 10^(len -1)이기에 우선 10^(len)만큼을 pow_add에 저장
    }
    
    for (i = 0; i < len; i++){  // 길이 만큼 반복
        num_check = num / pow % 10; // 일의 자리부터 각각의 자리수를 num_check에 저장
        pow *= 10;  // 한번 할때마다 10 ^ (1 + n)
        
        pow_add = pow_add / 10; // pow_add 는 * 10 ^1을 해줌
        result += (num_check * pow_add);    // num_check * pow_add를 result에 저장
        
    }
    printf("%d", result);   // 결과 출력

    return 0;
}
