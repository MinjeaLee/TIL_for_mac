#include <stdio.h>

int main(){
    int num, equal = 0, less = 0, greater = 0, inte;
    // 원하는 수, 동일할 때 카운트, 적을 떄 카운트, 클 때 카운트, 지속적으로 입력 받을 변수
    scanf("%d", &num);
    // 원하는 수 입력
    while(1){  // 무한루프
        scanf("%d", &inte); // 지속적으로 입력
        if (inte == 0){     // 입력받은 수가 0이라면 무한루프 탈출
            break;
        }
        if (num == inte){   // 동일 할때
            equal++;    // equal 카운트 증가
        }
        else if(num >= inte){   // 원하는 수가 입력받는 수보다 클떄
            less++;     // less 카운트 증가
        }
        else{   // 그외의 경우
            greater++;  // greater 카운트 증가
        }
    }
    printf("%d %d %d",equal, less, greater);    // 결과 출력

    return 0;
}