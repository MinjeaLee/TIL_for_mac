#include <stdio.h>

int main(){
    int num1, num2, result;
    // �Է¹��� ���� a,b,c�� ���� num1, num2, result�� ����
    scanf("%d %d %d", &num1, &num2, &result);
    // �� ���� �Է�
    if(num1 + num2 == result){
        // result�� num1�� num2�� +�������� �̷���� �ִٸ� +���
        printf("+\n");
    }
    if(num1 - num2 == result){
        // result�� num1�� num2�� -�������� �̷���� �ִٸ� -���
        printf("-\n");
    }
    if(num1 * num2 == result){
        // result�� num1�� num2�� *�������� �̷���� �ִٸ� *���
        printf("*\n");
    }
    if(num1 / num2 == result){
        // result�� num1�� num2�� -�������� �̷���� �ִٸ� -���
        printf("/\n");
    }
    if(num1 + num2 != result && num1 - num2 != result && num1 / num2 != result && num1 * num2 != result ){
        // result�� num1�� num2�� ��� ��꿹�� ���� �ƴ϶�� Incorrect���
        printf("Incorrect\n");
    }
    return 0;
}