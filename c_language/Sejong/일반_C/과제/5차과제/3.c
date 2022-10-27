#include <stdio.h>
//restore github

int multiple(int x, int y){         // multiple �Լ� ����
    if(x % y == 0){                 // x �� y�� ����̸�
        return  1;                  // 1 ��ȯ
    }
    else{                           // �׷��� ������ 
        return 0;                   // 0 ��ȯ
    }
}

int maximum(int x, int y){          // maximum�Լ� ����
    if(x > y){                      // x�� y���� ũ��
        return x;                   // x ��ȯ
    }
    else{                           // �׷��� ������
        return y;                   // y��ȯ
    }
}

int digit_maximum(int x){           // digit_maximum �Լ� ����
    int max = 0, num;               // max�� 0���� ����, �ڸ��� Ȯ���� ���� ����
    while(x != 0){                  // x�� 0�� �ƴҶ�����
        num = x % 10;               // num�� ����ؼ� 1�� �ڸ��� ����
        x /= 10;                    // x�� ����ؼ� /10
        max = maximum(max, num);    // max��
    }
    return max;                     // max ��ȯ
}

int main(){
    int n, m, k, max = 0, nmax = 0; // ���� n, m, k�� ����� ����� max ����� �ƴ� ����� max ����
    scanf("%d %d %d", &n, &m, &k);  // ���� �Է�
    for(int i = n; i <= m; i++){    // n���� m���� i�� 1�� �����ϸ�
        if(multiple(i, k)){         // i�� k�� ������
            max = maximum(max, digit_maximum(i));   // i�� �ڸ��� �ִ񰪰� ���� max�� �ִ��� ���Ͽ� �� ū���� max�� ���� 
        }
        else{                       // ����� �ƴϸ� 
            nmax = maximum(nmax, i % k);            // ������ nmax�� i�� k�� ���� �������߿��� �ִ��� nmax�� ����
        }
    }
    printf("%d", maximum(max, nmax));               // max�� nmax�� ���Ͽ� �� ū���� ���
    
    return 0;
}