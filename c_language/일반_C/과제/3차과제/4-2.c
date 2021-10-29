#include <stdio.h>

int main(){
    int num, inte, equal = 0, less = 0, greater = 0, len, len_check, i, pow, num_check;
    // 차례대로 원하는 숫자, 지속적으로 입력받을 숫자, 동등할떄 카운트, 적을 때 카운트, 클 떄 카운트, 숫자 길이 확인, 길이확인에 필요한 변수
    // for문 변수 , 10의 제곱을 계산하는 변수, 각자릿수를 저장하는 변수 선언
    scanf("%d", &num);  // 원하는 숫자 입력
    while(1){   // 무한루프
        len = 0;    // 길이를 0으로 초기화
        pow = 1;    // 10 ^ 0 = 1으로 초기화
        scanf("%d", &inte); // 지속적으로 입력받기
        if(inte == 0){  // 0이면
            break;  // 무한루프 탈출
        }
        len_check = inte;   // 길이를 확인하기 위해 , inte로 해버리면 길이 체크하는 과정에서 처음값과 달리지기에 다른 변수에 저장
        do{
            len_check = len_check / 10; // 변수 / 10한 것을 다시 변수에 저장
            len++;  // len 카운트 +1
        }while(len_check != 0); // 변수가 0이 아닐때 까지
        for(i = 0; i < len; i ++){  // 길이 만큼 반복
            num_check = inte / pow % 10;    // 일의 자리부터 각각의 자리수를 num_check에 저장
            pow *= 10;  // 한번 할때마다 10 ^ (1 + n)
            if (num_check == num){ // 동등하면  
                equal++;    // equal ++
            }
            else if(num >= num_check){  // 원하는 숫자가 더크면 
                less++; // less++
            }
            else{       // 이외의 경우
                greater ++; // greater ++
            }
        }
    }
    printf("%d %d %d", equal, less, greater); // 결과 출력
    return 0;
}