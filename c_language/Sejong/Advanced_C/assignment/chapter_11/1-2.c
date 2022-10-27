#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sutduent{

    char name[10], grade; // 학생이름, 등급
    char id[11], year[5];// 학번, 입학년도 
    
}stu;

int main(){
    stu chart[5], check_stu;         // 5명 구조체 배열 선언, 확인할 학생 정보를 담을 구조체 선언
    char check_name[10];        // 확인할 학생 이름 받을 문자열 선언
    int check = 0;                  // 학생이 있는 지 없는지를 체크할 변수 선언


    for(int i = 0; i < 5; i++){         // 5변 반복 
        scanf("%s %s %c", &chart[i].name, &chart[i].id, &chart[i].grade);   // 학생정보 입력
        strncpy(chart[i].year, chart[i].id, 4);     // 입학년도에 학번 앞에서 4글자
        chart[i].year[4] = '\0';    // 마지막 인덱스에 \0삽입
        getchar();      // \n getchar
    }
    scanf("%s", check_name);    // 확인할 학생 이름

    for(int i = 0; i < 5; i++){     // 배열확인
        if(strcmp(check_name, chart[i].name) == 0){     //확인할 학생의 경우
            check_stu = chart[i];                       // 구조체 복사
            break;                  
        }
    }
    

    for(int i = 0; i < 5; i++){         // 5번 반복
        if(strcmp(check_stu.year, chart[i].year) == 0 && check_stu.grade == chart[i].grade && strcmp(check_stu.name,chart[i].name) != 0){   // 입학년도가 같고, 성적이 같으며, 확인할 사람과 이름이 다른 경우 확인
            printf("%s ", chart[i].name);       // 이름 출력
            check = 1;      // 경우에 맞는 경우가 있으므로 check변수를 1로
        }
    }   
    if(check == 0){     // check이 0이면
        printf("0");        // 0출력
    }
    printf("\n");       // 줄바꿈
    printf("%s %d", check_stu.year, atoi(check_stu.year) % 131); // 확인할 학생 입학년도와 131로 나눈 나머지 출력
    
    return 0;
}