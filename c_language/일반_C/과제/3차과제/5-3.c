#include <stdio.h>

int main(){
    int num, len_check, len = 0, even = 0 , odd = 0, i, num_check, pow = 1;
    // 차례대로 입력받을 수, 수 길이 사용 변수, 길이 카운트, 역수가 아닌 짝수 저장 변수, 역수가 아닌 홀수 저장 변수, for문 변수, 자리수 확인, 10제곱 저장
    int pow_o = 1, pow_e = 1, result_e = 0, result_o = 0, len_e = 0, len_o = 0;
    // 홀수 역수 사용 10제곱, 짝수 역수 사용 10제곱, 짝수 역수 결과, 홀수 역수 결과, 짝수 길이, 홀수 길이 변수 선언
    scanf("%d", &num); // 수 입력
    len_check = num; // 길이를 확인하기 위해 , num으로 해버리면 길이 체크하는 과정에서 처음값과 달리지기에 다른 변수에 저장
    do{
        len_check = len_check / 10; // 변수 / 10한 것을 다시 변수에 저장
        len++;  // len 카운트 +1
    }while(len_check != 0); // 변수가 0이 아닐때 까지
    for(i = 0 ; i < len; i ++){ // 길이 만큼 반복
        num_check = num / pow % 10; // 일의 자리부터 각각의 자리수를 num_check에 저장
        pow *= 10;  // 한번 할때마다 10 ^ (1 + n)
        if (num_check % 2 == 0){    // 짝수라면
            even += (num_check * pow_e);     // num_check를 짝수에 저장
            pow_e *= 10;    // 짝수pow는 그다음 다음자리에 자장 가능하도로 * 10
            len_e ++;   // 짝수 길이 카운트도 ++ (for문에서 길이만큼 반복하기 위해)
        }
        else{
            odd += (num_check * pow_o); // num_check를 짝수에 저장
            pow_o *= 10;    // 짝수pow는 그다음 다음자리에 자장 가능하도로 * 10
            len_o ++;       // 짝수 길이 카운트도 ++ (for문에서 길이만큼 반복하기 위해)
        }
    }
    pow_e = pow_e / 10; // 위에서 10씩 더 곱해졌으니 10을 나눠줌
    pow_o = pow_o / 10; // 위에서 10씩 더 곱해졌으니 10을 나눠줌
    pow = 1;    // pow는 다시 1로 초기화
    for(i = 0; i < len_e; i++){ // 짝수저장한 길이 만큼 저장
        num_check = even / pow % 10;    // 일의 자리부터 각각의 자리수를 num_check에 저장
        pow *= 10;  // 한번 할때마다 10 ^ (1 + n)
        result_e += num_check * pow_e;  // 역수로 저장
        pow_e /= 10;    // pow를  10씩 나눠줌
    }
    pow = 1;    // pow는 다시 1로 초기화
    for(i = 0; i < len_o; i++){     // 홀수저장한 길이 만큼 저장
        num_check = odd / pow % 10; // 일의 자리부터 각각의 자리수를 num_check에 저장
        pow *= 10;  // 한번 할때마다 10 ^ (1 + n)
        result_o += num_check * pow_o;  // 역수로 저장
        pow_o /= 10;    // pow를  10씩 나눠줌
    }

    printf("%d %d", result_e, result_o);    // 결과

    return 0;
}