#include <stdio.h>

int main(){
    int num, len, len_check, i, num_check, pow, pow_add, result;
    // �Է� ���� ��, ���� ī��Ʈ, ���� üũ�ҋ� ���̴� ���� for���� ���̴� ����, ������ �ڸ���, �ڸ��� �����Ҷ� 10������, ������� �߰��Ҷ� ���̴� 10������, �����
    pow = 1;    // 10 ^0
    pow_add = 1;    // ���߿� �߰��� ���̹Ƿ� �켱 10^0
    result = 0; //������� 0���� �ʱ�ȭ
    len = 0;    // ���̵� 0���� �ʱ�ȭ
    scanf("%d", &num);  // �� �Է�
    len_check = num;    // ���̸� Ȯ���ϱ� ���� , num���� �ع����� ���� üũ�ϴ� �������� ó������ �޸����⿡ �ٸ� ������ ����
    do{
        len_check = len_check / 10; // ���� / 10�� ���� �ٽ� ������ ����
        len++;  // len ī��Ʈ +1
    } while(len_check != 0);    // ������ 0�� �ƴҶ� ����
    
    for(i = 0; i < len; i++){    // ���� ��ŭ �ݺ�
        pow_add *= 10;  // ó������ �������� ���Ҷ��� 10^(len -1)�̱⿡ �켱 10^(len)��ŭ�� pow_add�� ����
    }
    
    for (i = 0; i < len; i++){  // ���� ��ŭ �ݺ�
        num_check = num / pow % 10; // ���� �ڸ����� ������ �ڸ����� num_check�� ����
        pow *= 10;  // �ѹ� �Ҷ����� 10 ^ (1 + n)
        
        pow_add = pow_add / 10; // pow_add �� * 10 ^1�� ����
        result += (num_check * pow_add);    // num_check * pow_add�� result�� ����
        
    }
    printf("%d", result);   // ��� ���

    return 0;
}
