#include <stdio.h>

int main(){
    int num, equal = 0, less = 0, greater = 0, inte;
    // ���ϴ� ��, ������ �� ī��Ʈ, ���� �� ī��Ʈ, Ŭ �� ī��Ʈ, ���������� �Է� ���� ����
    scanf("%d", &num);
    // ���ϴ� �� �Է�
    while(1){  // ���ѷ���
        scanf("%d", &inte); // ���������� �Է�
        if (inte == 0){     // �Է¹��� ���� 0�̶�� ���ѷ��� Ż��
            break;
        }
        if (num == inte){   // ���� �Ҷ�
            equal++;    // equal ī��Ʈ ����
        }
        else if(num >= inte){   // ���ϴ� ���� �Է¹޴� ������ Ŭ��
            less++;     // less ī��Ʈ ����
        }
        else{   // �׿��� ���
            greater++;  // greater ī��Ʈ ����
        }
    }
    printf("%d %d %d",equal, less, greater);    // ��� ���

    return 0;
}