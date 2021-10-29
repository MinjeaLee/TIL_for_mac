#include <stdio.h>
#include <limits.h>

int *max(int *x);
int *min(int *x);
int *low_address(int *a, int *b);
int dif_address(int *a, int *b);


int main(){
    int n, arr[100];   // 사용자에게 받은 변수, 배열 선언
    int *p_n = &n, *p_arr; // 포인터 변수 선언
    int dif;            // 주소 차이를 저장할 변수 선언


    scanf("%d", p_n);   // 정수 입력

    for(int i = 0; i < *p_n; i++){  // 입력받은 정수 만큼 반복
        for(p_arr = arr; p_arr < arr + 100; p_arr++){   // 배열에 정수 입력
            scanf("%d", p_arr);                 // 정수 입력
            if(*p_arr == 0){                    // 0일때까지 입력받기
                break;
            }
        }
        if(dif_address(max(arr), min(arr))){        // 최댓값과 최솟값의 주소 차이가 양수 일경우
            dif = dif_address(max(arr), min(arr));  // 그 차이를 변수에 저장
            for(p_arr = low_address(max(arr), min(arr)) + 1; p_arr < low_address(max(arr), min(arr)) + dif; p_arr++){ // 낮은 주소 부터 높은 주소 까지 반복
                printf("%d ", *p_arr);  // 사이에 있는 값 출력
            }
            printf("\n");       // 다음 출력을 위해 줄바꿈
        }
        else{
            printf("none\n");   // 차이가 없다면 none 출력
        }
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

int *low_address(int *a, int *b){   // 최솟값 최대값의 주소 중 더 낮은 주소 반환
    int *add;   // 반환할 포인터 변수 선언
    if(a > b){  // a의 주소가 더 높으면 b의 주소를 저장
        add = b;
    }
    else{       // b의 주소가 더 높으면 a의 주소 저장
        add = a;
    }
    return add; // 주소 반환
}
int dif_address(int *a, int *b){    // 주소의 차이를 반환할 함수
    int *high, *low;    // 높은 주소, 낮의 주소를 저장할 포인터 변수 선언
    if(a > b){      // 높은 주소, 낮은 주소를 각각 저장
        high = a;
        low = b;
    }
    else{           // 높은 주소, 낮은 주소를 각각 저장
        low = a;
        high = b;
    }
    if(high - low <= 1){    // 만약 주소의 차이가 1 이하인 경우 연달아 있는 경우와 차이가 없는 경우 0 반환
        return 0;
    }
    else{                   // 그외의 경우 그 차이를 반환
        return high - low;
    }
}