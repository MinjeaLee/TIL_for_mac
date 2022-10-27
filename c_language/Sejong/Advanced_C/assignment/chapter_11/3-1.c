#include <stdio.h>
#include <string.h>

struct hotel_info       
{

    char name[31], meal_check;      // 호텔이름, 조식 여부
    int grade;      // 등급
    double reputation, distance;    // 평판, 거리
};

int in_hotel_info(struct hotel_info *p)
{
    int num = 0;        // 호텔 개수 저장 변수 선언

    for (;; p++)        // 무한반복, p가 증하하면서
    {
        scanf("%s", &p->name);  // 이름 입력
        if (strcmp(p->name, "0") == 0)  // 이름에 0이 입력될경우 break
        {
            break;
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reputation, & p->distance, &p->meal_check);       // 나머지 정보 입력
        getchar();  // \n getchar

        num++;  // 호텔수 ++
    }
    return num;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info *p_struct, max; // 구조체 포인터, 가장 큰 평판 가진 구조체 저장할 구조체 변수 선언
    double max_reputation = -1; // 평판의 최댓값 저장할 변수 우선 -1로 초기화
    int fast_check;     // 이름 순으로 정렬할 때 결과값 저장 변수 선언

    for (p_struct = p; p_struct < p + N; p_struct++)        // 반복
    {
        if (p_struct->grade >= G && p_struct->distance <= D)        // 조건이 일치하는 경우
        {
            if (p_struct->reputation > max_reputation)      // 평판 비교
            {
                max_reputation = p_struct->reputation;      // 최대 평판 값을 바꿈
                memcpy(&max, p_struct, sizeof(struct hotel_info)); // 구조체 복사
            }
            if (p_struct->reputation == max_reputation)     // 평판이 같은 경우
            {
                fast_check = strcmp(p_struct->name, max.name);  // 문자열 비교값 저장
                if (fast_check < 0)     // 이전의 max에 저장된 이름이 사전순으로 뒤에 있는 경우
                {
                    memcpy(&max, p_struct, sizeof(struct hotel_info));  // 구조체 복사
                }
            }
        }
    }
    printf("%s %d %.1lf %.1lf %c", max.name, max.grade, max.reputation, max.distance, max.meal_check);      // 결과 출력
}
int main()
{
    struct hotel_info chart[100];       // 구조체 배열 선언
    int hotels_num, grade;          // 호텔 개수 변수, 등급 변수 선언
    double distance;        // 거리 변수 선언

    hotels_num = in_hotel_info(chart);      // 호텔 개수 -> 함수 호출 반환값

    scanf("%d %lf", &grade, &distance);     // 조건(거리 등급) 입력

    out_hotel_info(chart, hotels_num, grade, distance);     // 함수 호출

    return 0;
}