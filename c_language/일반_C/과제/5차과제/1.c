#include <stdio.h>
//restore github

int num_digit(int n){       // num_digit �Լ� ����
    int len = 0;            // ����� ���� ����
    do{
        len++;              // len++
        n /= 10;            // n�� 10�� ����
    }while(n != 0);         // n�� 0�� �ƴҶ����� �ݺ�
    return len;             // ����� ��ȯ
}

int convert_top(int n, int len){    // convert_top�Լ� ����
    int pow = 1, convert;           // 10�� ������ ������ ����, ������ ���� ������ ���� ����
    if(len == 1){                   // len�� 1�� �ɋ����� ���� ��쿡 �� ��� 0�� �ǹǷ� ���� ����
        pow = 1;                    
    }
    else{   
        for(int i = 0; i < len; i++){   // ���̹�ŭ �ݺ�       
            pow *= 10;                  // 10 ^ (len)��ŭ ���� pow�� �����ϰ� ��
        }
        pow /= 100;                     // �� ���ڸ� �����ؾ��ϹǷ� / 100�� ����
    }
    convert = n / pow;                  // ������ ���� n / pow�� ����
    if('a' <= convert && convert <= 'z' || 'A' <= convert && convert <= 'Z'){       // ������ ���� ���ĺ� ������ ���
        printf("%c", convert);                                                      // %c�� ��ȯ�Ͽ� ���
    }
    else{                                                                           // �� �̿��� ���
        printf("*");                                                                // �� ���
    }
    n = n - (convert * pow);                                                        // n�� n�� ����� ���� pow�� ���� ���� ���� �Ǹ� ������ �� ���ڸ� ���� ����
    if(len - 2 > 0){                    //  len - 2�� ���� 0�̻��� ��� 
        return n;                       // ������ ���� ��ȯ
    }
    else{                               // �� ���� ���
        return 0;                       // 0 ��ȯ
    }
}

int convert_bottom(int n){              // convert_bottom�Լ� ����
    int convert;                        // ������ ���� ���� ���� ����
    convert = n % 100;                  // convert�� n % 100���� ����
    n /= 100;                           // n�� ���� 100�� ������ ����
    if('a' <= convert && convert <= 'z' || 'A' <= convert && convert <= 'Z'){ // ������ ���� ���ĺ��� �������
        printf("%c", convert);                                                // %c�� ��ȯ�Ͽ� ���
    }
    else{
        printf("*");                                                          // �� ���� ��� *�����
    }
    if(num_digit(n) > 0){                                                     // ������ ���̰� 0���� Ŭ ���
        return n;                                                             // ������ ���� ���
    }
    else{                                                                     // �� ���� ��� 
        return 0;                                                             // 0���
    }
}

int main(){
    int num, len;                                                             // �Է� ���� ���� ���� ����, ������ ���� ������ ���� ����
    scanf("%d", &num);                      // ���� �Է� 
    len = num_digit(num);                   // len�� num_digit�Լ� �̿��Ͽ� ����
    if(len % 2 != 0){                       // ���̰� ¦���� �ƴҰ��
        while(len >= 1){                    // len�� 1�̻��� ����
            num = convert_top(num, len);    // num�� convert_top�� ������� ����
            len -= 2;                       // len �� -2 �� ����
        }
    }
    else{                                   // �׿��� ���
        while(len > 0){                     // len�� 0���� Ŭ�� ����
            num = convert_bottom(num);      // num�� convert_bottom�� ������� ����
            len -= 2;                       // len �� -2 �� ����
        }
    }

    return 0;
}