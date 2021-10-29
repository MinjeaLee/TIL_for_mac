#include <stdio.h>
#include <limits.h> // 정수의 최소값, 최대값을 사용하기 위해 limits 헤더파일을 씀.

int main(){
    int max_x[20], i, j, n, max[7], min[7], max_num =INT_MIN, min_num = INT_MAX;
    // 수를 저장하는 배열(이는 max를 저장하는데 다시 쓰임.) for문 변수 i,j 몇개입력할 지 입력받는 변수n, 각 단계의 max와 min를 저장하는 배열, max를 정수의 최소값으로, min을 정수의 최대값으로 저장.
    int count = 0, min_x[20];
    // 각 단계의 배열의 수를 count할 변수, 0으로 저장, min을 저장하는데 쓰일 배열 선언
    scanf("%d", &n); // 변수n 입력
    for(i = 0; i < n; i++){
        scanf("%d", &max_x[i]); // 수를 입력받고 이를 차례대로씩 max_x에 저장 
        min_x[i] = max_x[i]; // 똑같이 min_x에 저장
    }
    for(i = 0; i < n; i++){
        printf(" %d", max_x[n - 1 - i]); // max_x의 수를 거꾸로 출력
    }
    printf("\n"); // 줄바꿈
    
    while(count != 1){ // 원소의 수가 1일 때까지 루프.
        count = 0; // 원소의 수를 0으로 초기화
        for(i = 0; i < n; i += 3){ // n까지 i를 3씩 증가하며
            count++;    // 원소의 수를 1개 늘림
            if(n % 3 == 0){ // n이 3의 배수라면
                for(j = 0; j < 3; j++){ // 3개씩 나누어 j를 증가하며
                    if(max_num < max_x[i+j]){ // max_x의 i+j번째 수가 max_num보다 크다면
                        max_num = max_x[i+j]; // 이를 max_num으로 저장
                    }
                    if(min_num > min_x[i+j]){ // min_x의 i+j번째 수가 min_num보다 크다면
                        min_num = min_x[i+j]; // 이를 min_num으로 저장
                    }
                }
            }
            else{ // n이 3의 배수가 아니라면
                if(i == n - (n % 3)){   // 마지막 max와 min을 판별할때 i가 n - n % 3이어야 함, 따라서 마지막 번째일때
                    for(j = 0; j < n % 3; j++){  // 나머지의 수만큼 반복
                        if(max_num < max_x[i+j]){// max_x의 i+j번째 수가 max_num보다 크다면
                            max_num = max_x[i+j];// 이를 max_num으로 저장
                        }
                        if(min_num > min_x[i+j]){// min_x의 i+j번째 수가 min_num보다 크다면
                            min_num = min_x[i+j];// 이를 min_num으로 저장
                        }
                    }
                }
                else{                       // 그 이외의 경우
                    for(j = 0; j < 3; j++){ // 3개씩 나누어 j를 증가하며
                        if(max_num < max_x[i+j]){// max_x의 i+j번째 수가 max_num보다 크다면
                            max_num = max_x[i+j];// 이를 max_num으로 저장
                        }
                        if(min_num > min_x[i+j]){// min_x의 i+j번째 수가 min_num보다 크다면
                            min_num = min_x[i+j];// 이를 min_num으로 저장
                        }
                    }

                }
            }
            max[count - 1] = max_num;   // 카운터의 -1 번째에 max배열에 각 번째의 최댓값을 저장
            min[count - 1] = min_num;   // 카운터의 -1 번째에 min배열에 각 번째의 최소값을 저장
            max_num = INT_MIN;  // 다시 max를 정수의 최소값으로, min을 정수의 최대값으로 저장.
            min_num = INT_MAX;
        }
        for(i = 0; i < count; i++){ // 원소의 수만큼 반복
            printf(" %d", max[i]);  // max의 원소를 순서대로 출력
            max_x[i] = max[i];  // 그 원소를 다시 판별하기 위해 max_x에 max의 워소를 순서대로 저장
        }   
        printf("\n");   // 줄바꿈
        for(i = 0; i < count; i++){ // 원소의 수만큼 반복
            printf(" %d", min[i]);  // min의 원소를 순서대로 출력
            min_x[i] = min[i];  // 그 원소를 다시 판별하기 위해 min_x에 min의 워소를 순서대로 저장
        }
        printf("\n"); // 줄바꿈
        n = count;  // n을 다시 카운트로 저장
    }
    return 0;
}