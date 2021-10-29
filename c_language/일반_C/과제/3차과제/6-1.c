#include <stdio.h>

int main(){
    int num, i, j;      // 입력 받을 수, for문 변수 선언
    scanf("%d", &num);      // 수 입력
    for(i = 1; i <= num ; i++){     // num번 반복
        for(j = 0; j < num - i; j++){       // num - i 만큼 빈칸 출력
            printf(" ");   
        }
        if(i == 1 || i == num){     // 1층일때와 마지막 층일때는 X만이 출력 되므로
            for(j = 0; j < 2 * i -1; j++){      // 2N - 1개수 만큼 별 출력
                printf("X");
            }
        }
        else{
            printf("X");        // 먼저 X출력
            for(j = 0; j < 2 * (i - 1) - 1; j++){   // 2(n-1)-1 개수 만큼 O출력
                printf("O");
            }
            printf("X");       // 끝에 X출력
        }
        printf("\n");       // 줄바꿈.
        
    }
    return 0;
}