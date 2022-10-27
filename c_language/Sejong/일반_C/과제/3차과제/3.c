#include <stdio.h>

int main(){
    int num, i, j, k, h; // 입력 받을 수 저장 변수, for문 변수들 선언
    scanf("%d", &num);  // 수 입력
    for(i = 0; i < num; i++){   // num까지의 층까지 출력
        for(j = num - i - 1; j > 0; j--){   // num - i - 1만큼 반복하며   
            printf(" ");    // 빈칸 출력
        }
        for(j = 0; j < 2 * i + 1; j++){ // 2n + 1 점화식 활용하여 별 출력
            printf("*");
        }
        printf("\n");   // 줄 바꿈
    }
    for(k = num - 1; k > 0; k--){   // 다이아의 총 줄의 개수가 총 2k - 1인데 위에서 k층까지 출력 했으므로 나머지 k - 1 층 출력
        for(h = 0; h < num - k; h++){   // num - k 만큼 반복
            printf(" ");        // 빈칸 출력
        }
        for(h = 2 * k - 1; h > 0; h--){ // k가 양수 부터 시작하므로 2k -1 개수 만큼 반복하며
            printf("*");    // 별 출력
        }
        printf("\n");   // 줄바꿈
    }
    return 0;
}

