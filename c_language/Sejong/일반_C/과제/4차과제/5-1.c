#include <stdio.h>

int main(){
    int x[100], num, i, check = 1, count = 0;
    // �迭x�� ũ�� 100���� �����ϰ� �Է¹��� ����, for�� ���� i, �ߺ� ���� �Ǵ� ���� check, �ߺ��� �ȵǴ� ���� ������ ���庯�� count����
    while(1){   // ���� ����
        check = 1;  // �켱 check�� 1�� ����
        scanf("%d", &num);  // �� �Է�
        
        if(num < 0){    // �����̸� ���� ���� Ż��
            break;
        }
        for(i = 0; i < count; i++){ // �迭 ������ ���� ��ŭ �ݺ�
            if(x[i] == num){    // ���� �� �� �ִٸ�
                check = 0;  // check�� 0���� �ϰ� 
                break;  // ���ѷ��� Ż��
            }
        }
        if (check == 1){    // �ߺ��� ���ٸ�
            x[count] = num; // count��°�� ����
            printf("1");    // 1���
            count++;        // count����
        }
        else if(check == 0){    // �ߺ��Ǵ� �����
            printf("0");    // 0���
        }
    }

    return 0;
}