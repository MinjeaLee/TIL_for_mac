#include <stdio.h>

struct _bank { 
    int id;         // 아이디
    int arrival_time;// 도착시간
    int service_time; // 서비스시간
    int waiting_time;// 대기시간
};

void waitingtime(struct _bank guest[], int N){
    int waiting;    // 대기시간 저장할 변수 선언

    for(int i = 0; i < N; i++){     // N번 반복
        waiting = 0;        // waiting을 0으로 초기화
        for(int j = 0; j < i; j++){       // i번째 까지, 자신의 앞번호 까지
            waiting += guest[j].service_time;   // 변수에 앞사람들의 서비스 시간을 더함
        }
        guest[i].waiting_time = waiting - guest[i].arrival_time;    // 구조체 변수에 자신의 도착시간을 뺀값을 대기시간에 저장
    }
}
double avgtime(struct _bank guest[], int N){        
    double sum = 0;     // 각각의 대기시간 저장할 변수
    for(int i = 0; i < N; i++){     // N번 반복
        sum += guest[i].waiting_time;       // 대기시간을 더함
    }
    return sum / N;     // 평균 계산하여 반환
}


int main(){
    int n;      // 사람수 저장 변수 선언
    struct _bank guest[100];        // 구조체 배열 선언

    scanf("%d", &n);        // 사람수 입력

    for(int i = 0; i < n; i++){     // n번 만큼 반복
        scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);        // 아이디, 도착시간, 서비스 시간 입력
    }
    waitingtime(guest, n);      // 함수 호출

    printf("%.2lf", avgtime(guest, n)); // 함수호출하여 결과값 출력

    return 0;
}