#include <stdio.h>

int main(){
    int i, x[20], f, r, m, vs, tmp;     // for�� ����, ����, F, R, M, �ٲ� �� �̿��� ����, �ӽ� ���� ����
    for(i = 1; i <= 20; i++){           // ���տ� 1���� 20�� ���� ����
        x[i -1] = i;
    }
    scanf("%d %d %d", &f, &r, &m);      // F, R, M �Է�
    vs = x[r];                          // �ʱ� VS�� x[r]�� ����
    for(i = 0; i < m; i++){             // m ��ŭ �ݺ�
        tmp = x[r - m + 1 + i];         // �ӽ� ���� ������ x[r - m + 1 + i]�� ����
        x[r - m + 1 + i] = vs;          //  vs�� ����
        vs = tmp;                       // vs�� x[r - m + 1 + i]���� �Ͽ� ���� ���࿡���� ���� �� �ְ� ��
    }
    for(i = 0; i < 20; i++){            // ���ʴ�� ���
        printf("%d ", x[i]);
    }
    
    return 0;
}