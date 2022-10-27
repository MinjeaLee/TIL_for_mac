#include <stdio.h>

int passengern(int n){      
    if(n < 5){      // 매개변수, 즉 승객 수가 5보다 작으면 -1 반환
        return -1;
    }
    else{           // 이외의 경우 0 반환
        return 0;
    }
}

int changeseat(int *ar){
    int check, empty; // 해당 숫자가 있는지 없는지 체크, 비어있는 숫자 저장할 변수 선언
    int *p; // 포인터 변수 선언
    for(int i = 1; i < 22; i++){    // 숫자가 1 ~ 21까지있으므로 모두 체크하기위해 반복
        check = 1;      //  체크 변수를 일단 1로 저장
        for(p = ar; *p != 0; p++){  // 0이 아닐 때까지 
            if(i == *p){    // 만약 해당 숫자가 있다면
                check = 0;  // 체크 변수를 0으로 바꾸고 반복문 탈출
                break;
            }
        }
        if(check){  // 만약 해당 숫자가 없었다면
            empty = i;  // 비어있는 숫자에 해당 숫자 저장
            break;  // 반복문 탈출
        }
    }
    return empty;   // 비어있는 숫자 (좌석) 반환

}
int rebooking(int *ar){
    int *p_i, *p_j, *last_address;  // 반복문에 사용할 포인터 변수와 가장 마지막 원소의 주소를 저장할 포인터 변수 선언
    int check_overlab_num;      // 중복되는지 체크할 변수 선언
    for(p_i = ar; *p_i != 0; p_i++){    // 0이 아닐때까지 반복
        last_address = p_i;             // 반복 시마다 마지막 주소를 초기화
    }

    for(p_i = ar; p_i < last_address - 1; p_i++){   //  마지막 주소 앞까지 반복
        check_overlab_num = *p_i;   // 체크 변수를 해당 원소로 초기화
        for(p_j = p_i + 1; *p_j != 0; p_j++){   // 해당 원소부터 배열 마지막까지 반복
            if(check_overlab_num == *p_j){  // 만약 중복이 된다면
                *p_j = changeseat(ar);  // 반환된 빈자리를 중복되는 원소에 저장
            }
        }
    }
}


int main(){
    int n, arr[21] = { 0, };    // 승객수, 좌석 배열을 선언, 좌석 배열의 경우 어디까지가 끝인지를 알기위해 모든 원소를 0으로 초기화
    int *p_n = &n, *p_arr;      // 포인터 변수 선언

    scanf("%d", p_n);   // 승객 수 입력

    for(p_arr = arr; p_arr < arr + n; p_arr++){ // 승객 수 만큼 반복
        scanf("%d", p_arr); // 좌석 번호 입력
    }
    if(passengern(n) == -1){    // 만약 5명 보다 적다면
        printf("-1");   // -1출력하고 프로그램 종료
        return 0;
    }
    else{   //이외의 경우 0 출력
        printf("0\n");
    }
    rebooking(arr); // 중복을 찾고 좌석 번호를 바꾸는 함수 호출

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        printf("%d ", *p_arr);          // 결과 출력
    }
    
    return 0;
}