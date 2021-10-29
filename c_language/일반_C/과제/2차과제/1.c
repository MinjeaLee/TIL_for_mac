#include <stdio.h>

int main(){
    int a, b, c, avg, max, min;
    // 세 과목의 점수를 저장할 변수 a,b,c를 선언
    // 평균, 최고점, 최저점을 저장할 변수 avg, max, min 선언
    scanf("%d %d %d", &a, &b, &c);
    // 세 과목의 점수 입력
    avg = (a + b + c) / 3;
    // 평균 값 계산
    if(a > b && a > c){
        // a과목이 다른 모든 과목 보다 점수가 높을 때 최고점은 a과목 
        max = a;
    }
    else if (b > a && b > c){
        // b과목이 다른 모든 과목 보다 점수가 높을 때 최고점은 b과목        
        max = b;
    }
    else{
        // a과목과 b과목이 최고점이 아니라면 c과목이 최고점        
        max = c;
    }
    if(a < b && a < c){
        // a과목이 다른 모든 과목 보다 점수가 낮을 때 최저점은 a과목
        min = a;
    }
    else if(b < a && b < c){
        // b과목이 다른 모든 과목 보다 점수가 낮을 때 최저점은 b과목
        min = b;
    }
    else{
        // a과목과 b과목이 최저점이 아니라면 c과목이 최저점
        min = c;
    }
    if(avg >= 90){
        // 평균이 90 이상일때 A출력
        printf("A\n");
    }
    else if (avg >= 80){
        // 평균이 80 이상일때 B출력
        printf("B\n");
    }
    else if(avg >= 70){
        // 평균이 70 이상일때 C출력
        printf("C\n");
    }
    else if(avg >= 60){
        // 평균이 90 이상일때 D출력
        printf("D\n");
    }
    else{
        // 그 이외의 경우 F출력
        printf("F\n");
    }

    printf("max: %d\nmin: %d", max, min);
    // 최고점과 최저점 차례로 출력
    return 0;
}