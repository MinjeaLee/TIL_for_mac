#include <stdio.h>
//restore github
#include <limits.h>         // �ּڰ��� int�� ���� �� �ִ� �ּڰ����� �����ϰ��ϱ� ���� limits.h�� ���Խ�Ŵ

int add_digits(int n){      // add_digit�Լ� ����
    int result = 0, num;    // ����� ���� ����, �� �ڸ��� ���� ���� ����
    if(n == 0){             // n�� 0�� ��� ���� while ���� ���� ������ ���� ���ϹǷ� ���� �������� ->result = 0
        result = 0;
    }
    while(n != 0){          // n�� 0�� ���
        num = n % 10;       // num�� n�� ���� �ڸ�
        result += num;      // result���� num�� +  
        n /= 10;            // n�� n / 10����
    }
    return result;          // reuslt ���� ��ȯ
}

int len_check(int x){       // ������ ���̸� �� �ʿ䰡 �־� len_check�Լ� ����
    int len = 0;            // len�� 0���� ����
    if(x == 0){             // x�� 0�� ��� ���� while���� �����Ƿ� len�� 1�� ����
        len = 1;
    }
    while(x != 0){          // x�� 0�� ���
        len++;              // len++
        x /= 10;            // x�� x / 10���� ����
    }
    return len;             // len �� ��ȯ
}

int main(){
    int num, len, num_check,min = INT_MAX, min_num;     // �Է¹��� ����, ������ ����, �Է¹��� ���ڸ� ������ ���� ����, �ּڰ��� int�� ���� �� �ִ� �ּڰ����� ����, �ּڰ��϶��� num�� ������ ���� ����
    while(1){                                       // ���ѷ���
        scanf("%d", &num);                          // ���� �Է�
        if(num < 0){                                // ���ڰ� ���� �϶� break
            break;
        }
        num_check = num;                            // num_check�� num����  ����
        len = len_check(num_check);                 // len ����
        while(len != 1){                            // len�� 1�� �ƴҶ����� �ݺ�
            num_check = add_digits(num_check);      // num_check�� add_digits(num_check)�� ������� ����
            len = len_check(num_check);             // num_check�� ���̸� len���� ����
        }
        if(num_check < min){                        // num_check �� min���� ���� ��
            min = num_check;                        // �ּڰ��� num_check�� ����
            min_num = num;                          // �ּ��϶��� ���ڸ� num���� ����
        }
    }

    printf("%d %d", min_num, min);                  // ���ʴ�� ����

    return 0;
}
