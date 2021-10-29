#include <stdio.h>
//restore github

int is_prime_number(int num){       // is_prime_number �Լ� ����
    int check = 1;                  // �Ҽ����� �ƴ����� �Ǵ��� ������ 1�� ����
    if(num == 1){                   // 1�� �Ҽ��� �ƴϹǷ�
        check = 0;                  // check�� 0����
    }
    for(int i = 2; i < num; i++){   // �Ҽ����� �Ǵ� �ϱ����� 2���� num - 1���� i�� 1�� ������Ű��
        if(num % i == 0){           // num�� i�� ������ �Ҽ��� �ƴϹǷ�
            check = 0;              // check �� 0���� �����ϰ� break
            break;
        }
    }
    return check;                   // check�� ��ȯ
}

int count_prime_number(int cnt, int num){           // count_prime_number �Լ� ���� 
    if(is_prime_number(num) && num < 100){          // �Ҽ��̸鼭 num�� 100���� ������
        return cnt + 1;                             // cnt+1�� ��ȯ
    }
    else{                                           // �̿ܿ��� 
        return 0;                                   // 0 ��ȯ
    }
}

int main(){
    int n, num, i, last_num, count = 0, max_count = 0;      // Ƚ��, ����, for������, ������ ���� ���� ����,���� ���� ���� ����, �ִ� ���� ���� ���� ����
    scanf("%d", &n);                                        // Ƚ�� �Է�
    for(i = 0; i < n; i++){                                 // Ƚ����ŭ �ݺ�
        scanf("%d", &num);                                  // ���� �Է�
        count = count_prime_number(count, num);             // count�� count_prime_number�Լ��� ��� �Ͽ� ����
        if(max_count < count){                              // max_count�� count���� ������
            max_count = count;                              // �׶��� count�� max_count�� ����
            last_num = num;                                 // �׶��� num�� last_num���� ����
        }
    }
    if(max_count == 0){                                     // max_count�� 0�̸�
        printf("0");                                        // 0 ���
    }
    else{                                                   // �̿ܿ���
        printf("%d\n", max_count);                          // max_count, last_num�� ���ʴ�� ���
        printf("%d", last_num);
    }
}