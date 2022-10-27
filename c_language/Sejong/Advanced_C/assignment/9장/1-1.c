#include <stdio.h>
#include <limits.h>

int *max(int *x);

int *min(int *x);

int main(){
    int n, arr[100]; // 사용자에게 받은 변수, 배열 선언
    int *p_n = &n, *p_arr; // 포인터 변수 선언

    scanf("%d", p_n); // 정수 입력

    for(int i = 0; i < *p_n; i++){  // n 만큼 반복
        for(p_arr = arr; p_arr < arr + 100; p_arr++){ // 배열에 정수 입력
            scanf("%d", p_arr);
            if(*p_arr == 0){    // 0이 입력될 경우 break
                break;
            }
        }
        printf("%d %d\n", *max(arr), *min(arr)); // 배열의 최댓값 최솟값 출력
    }

    return 0;
}

int *max(int *x){
    int max = INT_MIN;  // 반환할 변수, 정수 최솟값으로 초기화
    int *p_max = &max;  // 포인터 변수 선언 초기화
    for(int *p = x; *p != 0; p++){ // 원소가 0이 아닐 때까지 반복
        if(*p > max){ // 지금까지의 최댓값보다 클 경우
            max = *p;   // 해당 값을 최댓값으로
            p_max = p;  // 주소 또한 초기화
        }
    }
    return p_max;   // 최댓값 주소 반환
}

int *min(int *x){ 
    int min = INT_MAX;  // 반환할 변수, 정수 최댓값으로 초기화
    int *p_min = &min;  // 포인터 변수 선언, 초기화
    for(int *p = x; *p != 0; p++){  // 원소가 0이 아닐때까지 반복
        if(*p < min){   // 지금까지의 최솟값보다 작을 경우
            min = *p;   // 해당값 최솟값
            p_min = p;  // 주소 또한 초기화
        }
    }
    return p_min;   // 최솟값 주소 반환
}
