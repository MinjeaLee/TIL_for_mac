#include <stdio.h>

struct bike_info{

    int bike_id, tel, use_time, membership_type;// 자전거 번호, 전화번호, 사용시간, 정기권 종류
    char type, membership;// 정기권인지 일일권인지 저장, 정기권 가입 미가입
    double fee;// 요금

};

void input(struct bike_info *p, int N){
    struct bike_info *p_struct;// 구조체 포인터 선언

    for(p_struct = p; p_struct < p + N; p_struct++){// p + n 만큼 반복
        scanf("%d %d %c", &p_struct->bike_id, &p_struct->tel, &p_struct->type);// 자전거 아이디, 전화번호, 상품 입력
        if(p_struct->type == 'S'){// 상품이 정기권이면 나머지 정보 입력
            scanf(" %c %d %d",&p_struct->membership ,&p_struct->membership_type,&p_struct->use_time);
            
        }
        else{
            scanf(" %d", &p_struct->use_time);// 일일권이면 사용시간만 입력
        }
        getchar();// \n getchar
    }
}

void compute(struct bike_info *p, int N){
    struct bike_info *p_struct; // 구조체 포인터 선언
    int fee, over_time;// 요금, 초과 시간 저장 변수 선언

    for(p_struct = p; p_struct < p + N; p_struct++){// p + n번 만큼 반복
        fee = 0;// 요금을 0으로 초기화
        over_time = p_struct->use_time - 60; // 초과 시간 계산 저장

        if(over_time > 0){ // 초과시간이 있다면
            fee += (over_time / 5) * 200;// 5분당 200원 계산하여 저장
        }

        if(p_struct->type == 'S'){// 상품이 정기권이라면
            if(p_struct->membership == 'N'){    // 정기권 구매 비용 + 
                if(p_struct->membership_type == 7){
                    fee += 3000;
                }
                else if(p_struct->membership_type == 30){
                    fee += 5000;
                }
                else{
                    fee += 15000;
                }
                
            }

        }
        else{   // 일일권이라면
            fee += 1000; // 기본 요금 +
        }
        p_struct->fee = fee;//구조체에 저장
    }
}

void display(struct bike_info *p, int N){
    struct bike_info *p_struct;// 구조체 포인터 저장

    for(p_struct = p; p_struct < p + N; p_struct++){    // 결과 출력
        printf("%d %d %c %.0lf\n", p_struct->bike_id, p_struct->tel, p_struct->type, p_struct->fee);
    }
    
}


int main(){
    struct bike_info chart[100];   // 구조체 배열 선언
    int n;// 개수 저장 변수 선언

    scanf("%d", &n); // 개수 입력
    
    input(chart, n);  // 함수 호출
    compute(chart, n);
    display(chart, n);

    return 0;
}