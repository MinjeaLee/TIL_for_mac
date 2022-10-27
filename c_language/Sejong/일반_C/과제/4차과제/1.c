#include<stdio.h>

int main(){
    int n, x[100], count = 0, len, i, check = 0;    // 입력받을 변수n, 최대범위 배열 x, 다음 라운드의 원소 수를 세는 변수, for문 변수, ERROR체크 변수 선언
    scanf("%d", &n);    // n 입력
    if(!(1 <=n && n <= 100)){   // n이 범위를 벗어나면 cheak를 1로
        check = 1;  
    }
    for(i = 0; i < n; i++){     // n까지 반복하며
        if(check == 1){     // 이전에 check가 1이라면 break
            break;
        }
        scanf("%d", &x[i]);     // 점수 입력
        if(!(0 <=x[i] && x[i] <= 100)){     // 점수가 범위를 벗어나면 
            check = 1;      // cheak는 1로
        }
    }
    len = n;    // n을 len로 저장
    if(len == 1){       // 만약 len이 1이라면 첫번째 원소 출력
        printf("%d", x[0]);
    }
    while(len != 1){        // len이 1이 될때까지 반복 
        if(check != 0){     // 만약 cheak가 0이라면  ERROR출력하고 break
            printf("ERROR");
            break;
        }
        if(len % 2 == 0){   // 만약 len이 짝수라면
            for(i = 0; i < len; i+= 2){ // 부전승이 없으니 i를 2씩 증가하면 반복
                if(x[i] > x[i+1]){      // 첫번째 원소가 크다면
                    x[count] = x[i];    // 배열 x에 첫번째 원소를 저장
                }
                else{       // 첫번째 원소가 두번째 원소보다 크지 않다면
                    x[count] = x[i+1];  // 두번째 원소를 저장 차례대로
                }
                count++;        // 카운트는 1 증가
            }
        }
        else{           // 원소의 개수가 홀 수라면 -> 부전승이 있다면
            for(i = 0; i < len - 1; i+= 2){     // 끝 원소를 제외한 나머지 원소까지 i를 2씩 증가ㅁ하며 반복
                if(x[i] > x[i+1]){              //첫 번째 원소가 크다면
                    x[count] = x[i];            // 배열 x에 첫번째 원소를 저장
                }
                else{                           // 첫번째 원소가 두번째 원소보다 크지 않다면
                    x[count] = x[i+1];          // 두번째 원소를 저장 차례대로
                }
                count++;                        // 카운트는 1 증가
            }
            x[count] = x[len - 1];              // 마지막 원소는 -> 부전승
            count++;                            // x배열에 2저장
        }
        for(i = 0; i < count; i++){             // 카운트 수대로 반복
            printf("%d ", x[i]);                // X배열을 차례대로 출력
        }
        printf("\n");                           // 줄바꿈
        len = count;                            // 카운트를 len으로 저장
        count = 0;                              // count는 0으로 초기화
    }
    return 0;
}