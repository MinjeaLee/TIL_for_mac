#include <stdio.h>
//restore github

int is_prime_number(int num){       // is_prime_number �Լ� ����
    int check = 1;                  // �Ҽ����� �ƴ����� �Ǵ��� ������ 1�� ����
    for(int i = 2; i < num; i++){   // �Ҽ����� �Ǵ� �ϱ����� 2���� num - 1���� i�� 1�� ������Ű��
        if(num % i == 0){           // num�� i�� ������ �Ҽ��� �ƴϹǷ�
            check = 0;              // check �� 0���� �����ϰ� break
            break;
        }
    }
    return check;                   // check�� ��ȯ
}

int main(){
    int n, number, lim, i, count = 0;       // Ƚ��, �Է� ���� ��, ����� �Ҽ��� ����, for�� ����, �Ҽ��� ������ ������ ���� ����
    scanf("%d %d", &n, &lim);               // ȸ���� ����� �Ҽ��� ������ �Է�
    for(i = 0; i < n; i++){                 // n�� �ݺ�
        scanf("%d", &number);               // ���� �Է�
        if(is_prime_number(number) && count < lim && number != 1){      // �Ҽ��̰� ���ݱ����� ����� �Ҽ��� ������ ����� �Ҽ��� �������� ������, ���ڰ� 1�� �ƴѰ�쿡��
            printf(" %d", number);          // ���� ���
            count++;                        // ���ݱ��� ����� �Ҽ��� ����++
        }
    }
    if(count == 0){                         // ����� �Ҽ��� ���ٸ�
        printf("0");                        // 0 ���
    }

    return 0;
}