#include <stdio.h>

int main(){
    int num, inte, equal = 0, less = 0, greater = 0, len, len_check, i, pow, num_check;
    // ���ʴ�� ���ϴ� ����, ���������� �Է¹��� ����, �����ҋ� ī��Ʈ, ���� �� ī��Ʈ, Ŭ �� ī��Ʈ, ���� ���� Ȯ��, ����Ȯ�ο� �ʿ��� ����
    // for�� ���� , 10�� ������ ����ϴ� ����, ���ڸ����� �����ϴ� ���� ����
    scanf("%d", &num);  // ���ϴ� ���� �Է�
    while(1){   // ���ѷ���
        len = 0;    // ���̸� 0���� �ʱ�ȭ
        pow = 1;    // 10 ^ 0 = 1���� �ʱ�ȭ
        scanf("%d", &inte); // ���������� �Է¹ޱ�
        if(inte == 0){  // 0�̸�
            break;  // ���ѷ��� Ż��
        }
        len_check = inte;   // ���̸� Ȯ���ϱ� ���� , inte�� �ع����� ���� üũ�ϴ� �������� ó������ �޸����⿡ �ٸ� ������ ����
        do{
            len_check = len_check / 10; // ���� / 10�� ���� �ٽ� ������ ����
            len++;  // len ī��Ʈ +1
        }while(len_check != 0); // ������ 0�� �ƴҶ� ����
        for(i = 0; i < len; i ++){  // ���� ��ŭ �ݺ�
            num_check = inte / pow % 10;    // ���� �ڸ����� ������ �ڸ����� num_check�� ����
            pow *= 10;  // �ѹ� �Ҷ����� 10 ^ (1 + n)
            if (num_check == num){ // �����ϸ�  
                equal++;    // equal ++
            }
            else if(num >= num_check){  // ���ϴ� ���ڰ� ��ũ�� 
                less++; // less++
            }
            else{       // �̿��� ���
                greater ++; // greater ++
            }
        }
    }
    printf("%d %d %d", equal, less, greater); // ��� ���
    return 0;
}