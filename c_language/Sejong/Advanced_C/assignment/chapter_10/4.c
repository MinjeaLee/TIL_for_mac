#include <stdio.h>
#include <string.h>

int s_check(char *p, char *q){
    int total = 0;              // ��� ���� ���� ����
    char *p_str;                // ������ ����
    for(p_str = p; p_str <= q; p_str++){        // ���������� �������� Ž��
        if('a' <= *p_str && *p_str <= 'z'){     // �ҹ����� ���
            total++;                            // total ++
        }
    }

    return total;   // ��� ��ȯ
}

int main(){
    int k1, k2, m;      // k1, k2, m ���� ����
    char str[201];      // ���ڿ� ����

    scanf("%d\n%d %d", &m, &k1, &k2);       // k1, k2, m ����
    getchar();  // ���� getchar()

    for(int i = 0; i < m; i++){     // m ��ŭ �ݺ�
        gets(str);          // ���ڿ� �Է�
        if(strlen(str) < k2){           // k2 ���� ���ڿ� ���� �� ���� ū���
            if(s_check(str + k1, str + strlen(str) -1)){    // �������� ���ڿ� ���� �Ű������� �Լ� ȣ�� -> 0�� �ƴ� ���
                printf("%d\n", s_check(str + k1, str + strlen(str) -1));    // ��� ���
            }
        }
        else{           // k2���� ���ڿ����̺��� ���� ���
            if(s_check(str + k1, str + k2)){        // ������ �ּҿ� ���� �ּҸ� �Ű������� �Լ� ȣ�� -> 0�� �ƴѰ��
                printf("%d\n", s_check(str + k1, str + k2));        // ����� ���
            }
        }
    }
    return 0;
}