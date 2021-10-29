#include <stdio.h>
#include <limits.h>

int *max(int *x);
int *min(int *x);
int *low_address(int *a, int *b);
int dif_address(int *a, int *b);


int main(){
    int n, arr[100];   // ����ڿ��� ���� ����, �迭 ����
    int *p_n = &n, *p_arr; // ������ ���� ����
    int dif;            // �ּ� ���̸� ������ ���� ����


    scanf("%d", p_n);   // ���� �Է�

    for(int i = 0; i < *p_n; i++){  // �Է¹��� ���� ��ŭ �ݺ�
        for(p_arr = arr; p_arr < arr + 100; p_arr++){   // �迭�� ���� �Է�
            scanf("%d", p_arr);                 // ���� �Է�
            if(*p_arr == 0){                    // 0�϶����� �Է¹ޱ�
                break;
            }
        }
        if(dif_address(max(arr), min(arr))){        // �ִ񰪰� �ּڰ��� �ּ� ���̰� ��� �ϰ��
            dif = dif_address(max(arr), min(arr));  // �� ���̸� ������ ����
            for(p_arr = low_address(max(arr), min(arr)) + 1; p_arr < low_address(max(arr), min(arr)) + dif; p_arr++){ // ���� �ּ� ���� ���� �ּ� ���� �ݺ�
                printf("%d ", *p_arr);  // ���̿� �ִ� �� ���
            }
            printf("\n");       // ���� ����� ���� �ٹٲ�
        }
        else{
            printf("none\n");   // ���̰� ���ٸ� none ���
        }
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

int *low_address(int *a, int *b){   // �ּڰ� �ִ밪�� �ּ� �� �� ���� �ּ� ��ȯ
    int *add;   // ��ȯ�� ������ ���� ����
    if(a > b){  // a�� �ּҰ� �� ������ b�� �ּҸ� ����
        add = b;
    }
    else{       // b�� �ּҰ� �� ������ a�� �ּ� ����
        add = a;
    }
    return add; // �ּ� ��ȯ
}
int dif_address(int *a, int *b){    // �ּ��� ���̸� ��ȯ�� �Լ�
    int *high, *low;    // ���� �ּ�, ���� �ּҸ� ������ ������ ���� ����
    if(a > b){      // ���� �ּ�, ���� �ּҸ� ���� ����
        high = a;
        low = b;
    }
    else{           // ���� �ּ�, ���� �ּҸ� ���� ����
        low = a;
        high = b;
    }
    if(high - low <= 1){    // ���� �ּ��� ���̰� 1 ������ ��� ���޾� �ִ� ���� ���̰� ���� ��� 0 ��ȯ
        return 0;
    }
    else{                   // �׿��� ��� �� ���̸� ��ȯ
        return high - low;
    }
}