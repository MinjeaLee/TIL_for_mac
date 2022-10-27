#include <stdio.h>

struct bike_info{

    int bike_id, tel, use_time, membership_type;        // 자전거 번호, 전화번호, 사용시간, 정기권 종류
    char type, membership;  // 정기권인지 일일권인지 저장, 정기권 가입 미가입
    double fee; // 요금 

};

void input(struct bike_info *p, int N){
    struct bike_info *p_struct;     // 구조체 포인터 선언

    for(p_struct = p; p_struct < p + N; p_struct++){    // p + n 만큼 반복
        scanf("%d %d %c", &p_struct->bike_id, &p_struct->tel, &p_struct->type);     // 자전거 아이디, 전화번호, 상품 입력
        if(p_struct->type == 'S'){  // 상품이 정기권이면 나머지 정보 입력
            scanf(" %c %d %d",&p_struct->membership ,&p_struct->membership_type,&p_struct->use_time);
            
        }
        else{
            scanf(" %d", &p_struct->use_time);      // 일일권이면 사용시간만 입력
        }
        getchar();  // \n getchar
    }
}

void compute(struct bike_info *p, int N){
    struct bike_info *p_struct;         // 구조체 포인터 선언
    int fee, over_time;     // 요금, 초과 시간 저장 변수 선언

    for(p_struct = p; p_struct < p + N; p_struct++){        // p + n번 만큼 반복
        fee = 0; // 요금을 0으로 초기화
        over_time = p_struct->use_time - 60;    // 초과 시간 계산 저장

        if(over_time > 0){  // 초과시간이 있다면
            fee += (over_time / 5) * 200;       // 5분당 200원 계산하여 저장
        }

        if(p_struct->type == 'S'){ // 상품이 정기권이라면
            if(p_struct->membership == 'N'){    // 정기권이 없다면
                if(p_struct->membership_type == 7){ // 정기권 구매 비용 + 
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
            fee += 1000;    // 기본 요금 +
        }
        p_struct->fee = fee;    //구조체에 저장
    }
}

void display(struct bike_info *p, int N){   
    struct bike_info *p_struct; // 구조체 포인터 저장
    int d_total_fee = 0, s_total_fee = 0;
    // 일일권 요금, 정기권 요금 저장 변수 선언

    for(p_struct = p; p_struct < p + N; p_struct++){
        printf("%d %d %c %.0lf\n", p_struct->bike_id, p_struct->tel, p_struct->type, p_struct->fee);    // 정보 출력
        if(p_struct->type == 'D'){      // 일일권인 경우
            d_total_fee += p_struct->fee;   // 일일권 요금 변수에 +
        }
        else{   
            s_total_fee += p_struct->fee;       // 정기권인 경우 정기권 요금 변수에 +
        }
    }
    printf("%d %d %d", d_total_fee, s_total_fee, d_total_fee + s_total_fee);        // 요금 정보 출력
    
}

void sort_(struct bike_info *p, int N){     // 정렬 함수를 따로 함수로 만듬
    struct bike_info *p_i, *p_j, tmp;       // 구조체 포인터, 스왑과정에서 필요한 구조체 변수 선언

    for(p_i = p; p_i < p + N - 1; p_i++){       // 선택정렬 방식 사용
        for(p_j = p_i + 1; p_j < p + N; p_j++){     
            if(p_i->bike_id > p_j->bike_id){        // 자전거 아이디를 오름 차순 정렬
                tmp = *p_i;                 // 스왑 과정
                *p_i = *p_j;
                *p_j = tmp;
            }
        }
    }

}

void bike_info_sort(struct bike_info *p, int N){
    struct bike_info *p_i, *p_j, s[100], d[100];       // 구조체 포인터, 정기권인 경우와 일일권이 경우 따로 저장할 배열 선언
    int D_count = 0, S_count = 0;       // 각 배열의 인덱스 변수 선언
    for(p_i = p; p_i < p + N; p_i++){       // n번 반복
        if(p_i->type == 'S'){       // 정기권의 경우
            s[S_count] = *p_i;      // 정기권 배열에 저장
            S_count++;              // 정기권 인덱스 ++
        }
        else{
            d[D_count] = *p_i;      // 일일권의 경우 일일권 배열에 저장
            D_count++;              // 일일권 인덱스 ++
        }
    }
    sort_(s, S_count);      // 두 배열 정령
    sort_(d, D_count);

    for(int i = 0; i < D_count; i++){   // 정렬된 두 배열을 하나의 배열로 만드는 과정, d 배열 부터 시작, d 배열 원소 갯수 만큼 반복
        *(p + i) = d[i];        // 저장
    }
    for(int i = D_count; i < D_count + S_count; i++){       // d원소갯수의 인덱스 부터 시작
        *(p + i) = s[i - D_count];      // 저장
    }
}



int main(){
    struct bike_info chart[100];        // 구조체 배열 선언
    int n;                              // 개수 저장 변수 선언

    scanf("%d", &n);                    // 개수 입력
    
    input(chart, n);                // 함수 호출
    compute(chart, n);
    bike_info_sort(chart, n);
    display(chart, n);

    return 0;
}