#include <stdio.h>

int main(){
    int x[100], num, i, check = 1, count = 0;
    // 배열x를 크기 100으로 선언하고 입력받을 변수, for문 변수 i, 중복 여부 판단 변수 check, 중복이 안되는 수의 개수를 저장변수 count선언
    while(1){   // 무한 루프
        check = 1;  // 우선 check를 1로 선언
        scanf("%d", &num);  // 수 입력
        
        if(num < 0){    // 음수이면 무한 루프 탈출
            break;
        }
        for(i = 0; i < count; i++){ // 배열 원소의 개수 만큼 반복
            if(x[i] == num){    // 같은 수 가 있다면
                check = 0;  // check를 0으로 하고 
                break;  // 무한루프 탈출
            }
        }
        if (check == 1){    // 중복이 없다면
            x[count] = num; // count번째에 저장
            printf("1");    // 1출력
            count++;        // count증가
        }
        else if(check == 0){    // 중복되는 수라면
            printf("0");    // 0출력
        }
    }

    return 0;
}