#include <stdio.h>

int main(){
    int num1, num2, num3, total = 0;
    // �޴� ��ȣ�� 3�� �Է� �ޱ����� num1, num2, num3�� ����
    // ���İ��� �Ѿ��� ������ ���� total�� �����ϰ� 0���� �ʱ�ȭ
    scanf("%d %d %d", &num1, &num2, &num3);
    // �޴���ȣ 3�� �Է�
    if(num1 == 1){
        // 1�� ���ڰ� 1�̶�� Pizza���, total�� 15000���� ����.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num1 == 2){
        // 1�� ���ڰ� 2�̶�� Burger���, total�� 5000���� ����.
        printf("Burger\n");
        total += 5000;
    }
    else if(num1 == 3){
        // 1�� ���ڰ� 3�̶�� Salad���, total�� 4500���� ����.
        printf("Salad\n");
        total += 4500;
    }
    else if(num1 == 4){
        // 1�� ���ڰ� 4�̶�� Ice cream���, total�� 800���� ����.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num1 == 5){
        // 1�� ���ڰ� 5�̶�� Beverage���, total�� 500���� ����.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 1�� ���ڰ� 0�̶�� None���, total�� 0���� ����.
        printf("None\n");
        total += 0;
    }
    if(num2 == 1){
        // 2�� ���ڰ� 1�̶�� Pizza���, total�� 15000���� ����.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num2 == 2){
        // 2�� ���ڰ� 2�̶�� Burger���, total�� 5000���� ����.
        printf("Burger\n");
        total += 5000;
    }
    else if(num2 == 3){
        // 2�� ���ڰ� 3�̶�� Salad���, total�� 4500���� ����.
        printf("Salad\n");
        total += 4500;
    }
    else if(num2 == 4){
        // 2�� ���ڰ� 4�̶�� Ice cream���, total�� 800���� ����.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num2 == 5){
        // 2�� ���ڰ� 5�̶�� Beverage���, total�� 500���� ����.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 2�� ���ڰ� 0�̶�� None���, total�� 0���� ����.
        printf("None\n");
        total += 0;
    }
    if(num3 == 1){
        // 3�� ���ڰ� 1�̶�� Pizza���, total�� 15000���� ����.
        printf("Pizza\n");
        total += 15000;
    }
    else if(num3 == 2){
        // 3�� ���ڰ� 2�̶�� Burger���, total�� 5000���� ����.
        printf("Burger\n");
        total += 5000;
    }
    else if(num3 == 3){
        // 3�� ���ڰ� 3�̶�� Salad���, total�� 4500���� ����.
        printf("Salad\n");
        total += 4500;
    }
    else if(num3 == 4){
        // 3�� ���ڰ� 4�̶�� Ice cream���, total�� 800���� ����.
        printf("Ice cream\n");
        total += 800;
    }
    else if(num3 == 5){
        // 3�� ���ڰ� 5�̶�� Beverage���, total�� 500���� ����.
        printf("Beverage\n");
        total += 500;
    }
    else{
        // 3�� ���ڰ� 0�̶�� None���, total�� 0���� ����.
        printf("None\n");
        total += 0;
    }

    printf("Total:%dwon", total);
    // total ���
    return 0;
}