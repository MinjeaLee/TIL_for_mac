#include <stdio.h>

int main(){
    int n, arr[21];     // 승객수와 좌석 배열 선언
    int *p_n = &n, *p_arr, *p_i, *p_j;  // 포인터 변수 선언
    int count_overlap_arr = 0, count_overlap_num, overlap_num; // 배열에 중복이 있는지 없는지를 저장, 각각의 숫자가 몇번 중복되는 지, 어떤 숫자가 중복되는지 체크할 변수 선언

    scanf("%d", p_n);   // 승객 수 입력

    for(p_arr = arr; p_arr < arr + n; p_arr++){ // 승객 수 만큼 반복
        scanf("%d", p_arr); // 좌석 번호 입력
    }
    if(n < 5){  // 그 수가 5보다 작다면
        printf("-1");   // -1 출력 하고 프로그램 종료
        return 0;
    }

    for(p_i = arr; p_i < arr + n; p_i++){   // 승객 수 만큼 반복
        overlap_num = *p_i;         // 체크할 숫자 저장
        count_overlap_num = 0;  // 카운트를 0으로 초기화
        for(p_j = arr; p_j < arr + n; p_j++){   // 승객 수 만큼 반복
            if(overlap_num == *p_j){    // 만약 같다면
                count_overlap_num++;    // 카운트를 +1 해주고
                *p_j = -1;              // 중복 체크를 막기 위해 -1로 변환
            }
        }
        if(count_overlap_num > 1 && overlap_num != -1){ // 체크할 숫자가 0이 아니고 1보다 클때(체크할떄 무조건 +1이 되기 떄문)
            count_overlap_arr++;    // 중복 카운트 +1
            printf("%d %d\n", overlap_num, count_overlap_num);  // 결과 출력
        }
    }

    if(count_overlap_arr == 0){         // 배열에 중복이 없다면
        printf("0");    // 0 출력
    }
    return 0;
}