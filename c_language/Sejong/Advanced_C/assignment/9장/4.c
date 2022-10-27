#include <stdio.h>
#include <limits.h>

void swap(int *x, int *y){  // 두 원소의 주소를 매겨변수로 하여 두 원소의 위치를 바꿀 함수 선언
    int tmp;

    tmp = *x;
    *x = *y;        // 두 위치를 바꿈
    *y = tmp;
}

// 병합 정렬과 유사한 방식을 사용
void sort(int *arr, int n){     // 배열을 내림차순으로 정렬할 함수 
    int *p_i, *p_j; // 포인터 변수 선언
    for(p_i = arr; p_i < arr + n - 1; p_i++){ // 선택 정렬 알고리즘 사용 배열의 길이보다 -1 만큼 반복, 원소 선택 
        for(p_j = p_i + 1; p_j < arr + n; p_j++){   // 비교할 원소 선택
            if(*p_i < *p_j){        // 만약 뒤의 원소가 더 클경우 
                swap(p_i, p_j); // 두 원소 스왑
            }
        }
    }
}

void reverse(int *arr, int n){  // 배열을 오름차순으로 정렬할 함수
    int *p_i, *p_j;     // 포인터 변수 선언
    for(p_i = arr; p_i < arr + n - 1; p_i++){   // 이또한 선택 정렬 사용
        for(p_j = p_i + 1; p_j < arr + n; p_j++){   
            if(*p_i > *p_j){        // 뒤의 원소가 더 작을 경우 
                swap(p_i, p_j); // 두 원소 스왑
            }
        }
    }
}

int main(){
    int x[10], y[10], buf, n = 0, m = 0;    // 배열 선언, 일단 입력 받고 입력을 종료할 지를 결정하는 변수, n, m선언
    int *p_i, *p_tmp = &buf, *x_start, *y_start;    // 포인터 변수 선언, x배열과 y배열을 비교 할때의 시작지점을 저장할 포인터 변수 선언


    for(p_i = x; ; p_i++){      // 무한 반복
        scanf("%d", p_tmp); // 정수 입력
        if(*p_tmp != 0){    // 0이 아닐아니라면
            *p_i = *p_tmp;  // 배열에 저장
            n++;    // n++
        }
        else{
            break;  // 0을 입력 받으면 입력 종료
        }
    }
    
    for(p_i = y; ; p_i++){  // y배열도 x배열과 같은 방식으로 원소 입력
        scanf("%d", p_tmp);
        if(*p_tmp != 0){
            *p_i = *p_tmp;
            m++;
        }
        else{
            break;
        }
    }

    sort(x, n);     // x배열 정렬
    sort(y, m);     // y배열 정렬
    x_start = x;    // x의 시작지점을 x배열의 시작지점으로 초기화
    y_start = y;    // y의 시작지점을 y배열의 시작지점으로 초기화


    for(int i = 0; i < n; i++){ //  x 배열의 크기만큼 반복
        if(*x_start > *y_start){    // x시작지점의 원소와 y시작지점의 원소 비교 x배열의 시작 원소가 크다면   
            printf("%d ", *x_start);        // 이를 출려
            x_start++;  // x의 시작지점을 옆으로 옮김
        }
        else{
            printf("%d ", *y_start); // y배열의 시작 원소가 크다면 이를 출력하고
            y_start++;  // y시작지점으로 옆으로 옮김
        }
        if(x_start >= x + n){   // 만약 x 시작주소가 x 배열을 벗어난다면
            *x_start = INT_MIN; // 벗어난 주소의 값을 정수 최솟값으로 하여 출력이 안되게 함
        }
        if(y_start >= y + m){   // 위와 동일 
            *y_start = INT_MIN;
        }
    }
    printf("\n");   // 줄바꿈

    reverse(x, n);  // 역으로 정렬
    reverse(y, m);  // 역으로 정렬
    x_start = x;    // 시작지점을 x배열의 시작 지점으로 초기화
    y_start = y;    // 위와 동일

    for(int i = 0; i < m; i++){ // y배열의 크기만큼 반복
        if(*x_start < *y_start){    // x시작지점의 원소와 y시작지점의 원소 비교 x배열의 시작 원소가 작다면
            printf("%d ", *x_start);    // 이를 출력
            x_start++;  // x 시작 지점을 옆으로 옮김
        }
        else{
            printf("%d ", *y_start);  // y배열의 시작 원소가 크다면 이를 출력하고
            y_start++;  // y 시작 지점을 옆으로 옮김
        }
        if(x_start >= x + n){   // 만약 x 시작주소가 x 배열을 벗어난다면
            *x_start = INT_MAX; //벗어난 주소의 값을 정수 최댓값으로 하여 출력이 안되게 함
        }
        if(y_start >= y + m){   // 위와 동일
            *y_start = INT_MAX;
        }
    }


    return 0;
}