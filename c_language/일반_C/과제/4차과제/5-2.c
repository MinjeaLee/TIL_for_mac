#include <stdio.h>

int main(){
    int x[100], y[100], result[200], num ,i = 0, x_n, y_n , count = 0, check = 0, j, tmp; // a집합, b집합, 합집합 크기를 각각 100, 100, 200으로 선언하고, 입력받을 변수, for, while문 변수, 각 집합의 len, 합집합의 len, 중복 체크 변수, 임시 저장 변수 선언
    while(1){               // 무한 루프
        scanf("%d", &num);  // 숫자 입력
        if(num < 0){        // 음 수라면
            break;          // break
        }
        x[i] = num;         // a집합에저장
        i++;                // i++  
    }
    x_n = i;                // 최종 i를 a집합의 len으로 설정
    i = 0;                  // i 초기화
    while(1){               // 무한 루프
        scanf("%d", &num);  // 숫자 입력
        if(num < 0){        // 음 수라면
            break;          // break
        }
        y[i] = num;         // B집합에저장
        i++;                // i++ 
    } 
    y_n = i;                // 최종 i를 B집합의 len으로 설정
    for(i = 0; i < x_n; i++){               // a집합 len만큼 반복
        check = 0;                          // 중복 체크 변수를 0으로
        for(j = 0; j < count; j++){         // 합집합의 len 만큼 반복하며
            if(x[i] == result[j]){          // 중복되는 수가 있는지 체크
                check = 1;                  // 중복이 있다면 check변수를 1로 저장하고 break
                break;
            }
        }
        if(check == 0){                     // 중복이 없다면
            result[count] = x[i];           // result에 차례대로 저장
            count++;                        // 합집합의 len++
        }
    }
    for(i = 0; i < y_n; i++){               // b집합 len만큼 반복
        check = 0;                          // 중복 체크 변수를 0으로
        for(j = 0; j < count; j++){         // 합집합의 len 만큼 반복하며
            if(y[i] == result[j]){          // 중복되는 수가 있는지 체크
                check = 1;                  // 중복이 있다면 check변수를 1로 저장하고 break
                break;
            }
        }
        if(check == 0){                     // 중복이 없다면
            result[count] = y[i];           // result에 차례대로 저장
            count++;                        // 합집합의 len++
        }
    }
    for(i = 0; i < count - 1; i++){         // 선택 정렬 알고리즘 인덱스가 0부터 len - 1까지 선택
        for(j = i + 1; j < count; j++){     //  i + 1부터 집합의 끝까지를 보며
            if(result[i] > result[j]){      //  j 보다 i가 더 큰것이 있다면
                tmp = result[j];            // 스왑
                result[j] = result[i];
                result[i] = tmp;
            }
        }
    }
    for(i = 0; i < count; i++){             // 차례대로 출력
        printf(" %d", result[i]);
    }

    return 0;    
}