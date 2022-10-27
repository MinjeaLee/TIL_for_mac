#include <stdio.h>
#include <limits.h>

int *max(int *x);

int *min(int *x);

int main(){
    int n, arr[100]; // ����ڿ��� ���� ����, �迭 ����
    int *p_n = &n, *p_arr; // ������ ���� ����

    scanf("%d", p_n); // ���� �Է�

    for(int i = 0; i < *p_n; i++){  // n ��ŭ �ݺ�
        for(p_arr = arr; p_arr < arr + 100; p_arr++){ // �迭�� ���� �Է�
            scanf("%d", p_arr);
            if(*p_arr == 0){    // 0�� �Էµ� ��� break
                break;
            }
        }
        printf("%d %d\n", *max(arr), *min(arr)); // �迭�� �ִ� �ּڰ� ���
    }

    return 0;
}

int *max(int *x){
    int max = INT_MIN;  // ��ȯ�� ����, ���� �ּڰ����� �ʱ�ȭ
    int *p_max = &max;  // ������ ���� ���� �ʱ�ȭ
    for(int *p = x; *p != 0; p++){ // ���Ұ� 0�� �ƴ� ������ �ݺ�
        if(*p > max){ // ���ݱ����� �ִ񰪺��� Ŭ ���
            max = *p;   // �ش� ���� �ִ�����
            p_max = p;  // �ּ� ���� �ʱ�ȭ
        }
    }
    return p_max;   // �ִ� �ּ� ��ȯ
}

int *min(int *x){ 
    int min = INT_MAX;  // ��ȯ�� ����, ���� �ִ����� �ʱ�ȭ
    int *p_min = &min;  // ������ ���� ����, �ʱ�ȭ
    for(int *p = x; *p != 0; p++){  // ���Ұ� 0�� �ƴҶ����� �ݺ�
        if(*p < min){   // ���ݱ����� �ּڰ����� ���� ���
            min = *p;   // �ش簪 �ּڰ�
            p_min = p;  // �ּ� ���� �ʱ�ȭ
        }
    }
    return p_min;   // �ּڰ� �ּ� ��ȯ
}
