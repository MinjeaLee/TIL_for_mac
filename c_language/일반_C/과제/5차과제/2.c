#include <stdio.h>
//restore github

int SumMultiple(int Start, int End, int X);     // SumMultiple �Լ� ����

int gcd(int x, int y){                          // �䱸���� 3)�� ���� �Ǹ� �ּҰ������ Ǫ�°� �����ϹǷ� m,n�� �ּҰ������ 
//���ؾ��Ѵ�. �ּҰ������ �� ���� �� / �� ���� �ִ����� �̹Ƿ� �ִ� ������� ���� �ʿ䰡 �ִ�. �ִ������� ��Ŭ����ȣ������
// �̿��ؼ� Ǯ������ �Լ����� gcd�� int���� x, y�� �� �Լ��� �����Ͽ���.
    int tmp;                        // ������ �ϱ����� ���� ����
    if(y == 0){                     // ������ ���� 0�̸� ������ ���Ƿ� �ٷ� 1�� ��ȯ�ϵ��� ��.
        return 1;
    }
    if(x < y){                      // x�� �� ū ���� ���� �� �ֵ��� �ϱ����� x�� y���� �۴ٸ�
        tmp = x;                    // x, y�� ���� �ٲ��ش�.
        x = y;
        y = tmp;
    }
    if(x % y == 0){                 // �������� �� �������� 0�̸� �� ���� �ִ� ������� ������ �ǹǷ� ������ ��ȯ�ϵ��� ��.
        return y;
    }
    else{                           // �������� ������ ������ �� �������� ������ ���� ��꿡�� �������� ���� �������� �Ͽ� �������� 0�϶� ���� �ٽ� gcd�� ȣ���ϵ��� ��.
        return gcd(y, x % y);
    }
}

int main(){
    int s, e, n, m;                 // s,e,n,m ����
    int n1, n2, n3, n4, n5, n6;     // �� �ٿ� ��µ� ������� ������ ���� ����
    scanf("%d %d %d %d", &s, &e, &n, &m);       // s,e,n,m �Է�

    n1 = SumMultiple(s, e, n);      //  s �̻� e �̸��� ���� �� n�� ����� ��
    n2 = SumMultiple(s, e, m);      //  s �̻� e �̸��� ���� �� m�� ����� ��
    n3 = SumMultiple(s, e, n * m / gcd(n, m));      // n��� �̸鼭 m�� ����� n,m�� ������̹Ƿ� SumMultiple�� s, e, n�� m�� �ּҰ������ ���ڷ� �־� �ּҰ������ ����� ���� �����ϰ� ��.
    n4 = SumMultiple(s, e, n) + SumMultiple(s, e, m) - SumMultiple(s, e, n * m / gcd(n, m));   
    // s �̻� e �̸��� ���� �� n�� ����̰ų� m�� ����� ���� ���� s���� e-1������ n�� ����� m�� ����� ��� ���ϸ� ������� ����� ��ġ�Ƿ� ������� ����� ���� ����. 
    n5 = SumMultiple(s, e, m) - SumMultiple(s, e, n * m / gcd(n, m));
    // s �̻� e �̸��� ���� �� m�� ����̸鼭 n�� ����� �ƴ� ���� ���� s���� e-1������ m�� ����� �տ��� m�� n�� �ּҰ������ ���� ����.
    n6 = SumMultiple(s, e, 1) - SumMultiple(s, e, n) - SumMultiple(s, e, m) + SumMultiple(s, e, n * m / gcd(n, m));
    // s �̻� e �̸��� ���� �� n�� ����� m�� ����� �ƴ� ���� ���� s���� e-1������ �տ��� n�� ����� �հ� m�� ����� ���� ���ָ� �ּҰ������ ����� ���� �ߺ��Ǿ� ������ �ǹǷ� ����.

    printf("%d\n%d\n%d\n%d\n%d\n%d", n1, n2, n3, n4, n5, n6); // ���ʴ�� ���
}

int SumMultiple(int Start, int End, int X){  // �Լ� ����
    int result = 0;                                         // ����� ������ ���� ����
    for(int i = Start; i < End; i++){                       // start���� end-1���� i �� 1�� ������Ű��
        if(i % X == 0){                                     //  i�� X�� ����̸�
            result += i;                                    // result�� ����.
        }
    }
    return result;                                          // result ��ȯ
}

