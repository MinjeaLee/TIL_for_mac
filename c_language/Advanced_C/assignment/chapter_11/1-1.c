#include <stdio.h>
#include <string.h>

typedef struct sutduent{

    char name[10], grade;       // 학생이름, 등급
    int id;                 // 학번

}stu;

int main(){

    stu chart[5];   // 5명 구조체 배열 선언
    char check_name[10];            // 확인할 학생 이름 받을 문자열 선언

    for(int i = 0; i < 5; i++){ // 5명 반복
        scanf("%s %d %c", &chart[i].name, &chart[i].id, &chart[i].grade);       // 이름 학번 성적 입력
        getchar();      // \n getchar
    }
    scanf("%s", check_name);        // 확인할 학생 이름 

    for(int i = 0; i < 5; i++){     // 배열확인
        if(strcmp(check_name, chart[i].name) == 0){     // 입력받은 이름과 같은 것이 있다면
            printf(" %d %c", chart[i].id, chart[i].grade);      // 학생 정보 출력
        }
    }

    return 0;
}