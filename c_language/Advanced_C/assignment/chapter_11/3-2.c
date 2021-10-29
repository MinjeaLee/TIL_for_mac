#include <stdio.h>
#include <string.h>

struct hotel_info
{

    char name[31], meal_check;  // 호텔이름, 조식 여부
    int grade;      // 등급
    double reputation, distance;    // 평판, 거리
};

int in_hotel_info(struct hotel_info *p)
{
    int num = 0;    // 호텔 개수 저장 변수 선언

    for (;; p++)      // 무한반복, p가 증하하면서
    {
        scanf("%s", &p->name);      // 이름 입력
        if (strcmp(p->name, "0") == 0)
        {            // 이름에 0이 입력될경우 brea
            break;
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reputation, &p->distance, &p->meal_check);        // 나머지 정보 입력
        getchar();      // \n getchar

        num++;      // 호텔수 ++
    }
    return num;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info sort[100], *p_i, *p_j, tmp;       // 정렬할 구조체 배열, 구조체 포인터, 구조체를 바꿀때 필요한 구조체 변수 선언
    double max_reputation = -1;     // 평판의 최댓값 저장할 변수 우선 -1로 초기화
    int sort_index = 0; // 정렬할 구조체 배열의 인덱스 나타낼 변수 선언

    for(p_i = p; p_i < p + N; p_i++){       // p + n만큼 반복
        if(p_i -> grade >= G && p_i -> distance <= D){  // 조건과 일치하는 경우
            sort[sort_index] = *p_i;        // sort에 append
            sort_index++;   //  sort 인덱스 ++
        }
    }

    for(p_i = sort; p_i < sort + sort_index - 1; p_i++){    // 선택정렬 사용
        for(p_j = p_i + 1; p_j < sort + sort_index; p_j++){
            if(p_i->reputation < p_j->reputation){  // 평판이 뒤에 것이 더 큰 경우
                tmp = *p_i; // 스왑
                *p_i = *p_j;
                *p_j = tmp;
            }
            else if(p_i->reputation == p_j->reputation){    // 평판이 같은경우
                if(strcmp(p_i->name, p_j->name) > 0){       // 사전순으로 빠른 것 정렬
                    tmp = *p_i;     // 스왑
                    *p_i = *p_j;
                    *p_j = tmp;
                }
            }
        }
    }


    for(p_i = sort; p_i < sort + sort_index; p_i++){    // sort배열 출력
        printf("%s %d %.1lf %.1lf %c\n", p_i->name, p_i->grade, p_i->reputation, p_i->distance, p_i->meal_check);
    }


}
int main()
{
    struct hotel_info chart[100];   // 구조체 배열 선언
    int hotels_num, grade;  // 호텔 개수 변수, 등급 변수 선언
    double distance;    // 거리 변수 선언

    hotels_num = in_hotel_info(chart);      // 호텔 개수 -> 함수 호출 반환값

    scanf("%d %lf", &grade, &distance);     / 조건(거리 등급) 입력


    out_hotel_info(chart, hotels_num, grade, distance);     // 함수 호출

    return 0;
}