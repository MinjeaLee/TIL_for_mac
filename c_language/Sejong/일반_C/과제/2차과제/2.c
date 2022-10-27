#include <stdio.h>

int main(){
    int num1, num2, num3, total = 0;
    // 메뉴 번호를 3개 입력 받기위한 num1, num2, num3를 선언
    // 음식값의 총액을 저장할 변수 total을 선언하고 0으로 초기화
    scanf("%d %d %d", &num1, &num2, &num3);
    // 메뉴번호 3개 입력
    if(num1 == 1){
        // 1번 숫자가 1이라면 Pizza출력, total에 15000원을 증액.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num1 == 2){
        // 1번 숫자가 2이라면 Burger출력, total에 5000원을 증액.
        printf("Burger\n");
        total += 5000;
    }
    else if(num1 == 3){
        // 1번 숫자가 3이라면 Salad출력, total에 4500원을 증액.
        printf("Salad\n");
        total += 4500;
    }
    else if(num1 == 4){
        // 1번 숫자가 4이라면 Ice cream출력, total에 800원을 증액.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num1 == 5){
        // 1번 숫자가 5이라면 Beverage출력, total에 500원을 증액.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 1번 숫자가 0이라면 None출력, total에 0원을 증액.
        printf("None\n");
        total += 0;
    }
    if(num2 == 1){
        // 2번 숫자가 1이라면 Pizza출력, total에 15000원을 증액.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num2 == 2){
        // 2번 숫자가 2이라면 Burger출력, total에 5000원을 증액.
        printf("Burger\n");
        total += 5000;
    }
    else if(num2 == 3){
        // 2번 숫자가 3이라면 Salad출력, total에 4500원을 증액.
        printf("Salad\n");
        total += 4500;
    }
    else if(num2 == 4){
        // 2번 숫자가 4이라면 Ice cream출력, total에 800원을 증액.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num2 == 5){
        // 2번 숫자가 5이라면 Beverage출력, total에 500원을 증액.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 2번 숫자가 0이라면 None출력, total에 0원을 증액.
        printf("None\n");
        total += 0;
    }
    if(num3 == 1){
        // 3번 숫자가 1이라면 Pizza출력, total에 15000원을 증액.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num3 == 2){
        // 3번 숫자가 2이라면 Burger출력, total에 5000원을 증액.
        printf("Burger\n");
        total += 5000;
    }
    else if(num3 == 3){
        // 3번 숫자가 3이라면 Salad출력, total에 4500원을 증액.
        printf("Salad\n");
        total += 4500;
    }
    else if(num3 == 4){
        // 3번 숫자가 4이라면 Ice cream출력, total에 800원을 증액.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num3 == 5){
        // 3번 숫자가 5이라면 Beverage출력, total에 500원을 증액.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 3번 숫자가 0이라면 None출력, total에 0원을 증액.
        printf("None\n");
        total += 0;
    }

    printf("Total:%dwon", total);
    // total 출력
    return 0;
}