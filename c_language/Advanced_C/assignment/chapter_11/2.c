#include <stdio.h>

struct _bank { 
    int id;         // ���̵�
    int arrival_time;// �����ð�
    int service_time; // ���񽺽ð�
    int waiting_time;// ���ð�
};

void waitingtime(struct _bank guest[], int N){
    int waiting;    // ���ð� ������ ���� ����

    for(int i = 0; i < N; i++){     // N�� �ݺ�
        waiting = 0;        // waiting�� 0���� �ʱ�ȭ
        for(int j = 0; j < i; j++){       // i��° ����, �ڽ��� �չ�ȣ ����
            waiting += guest[j].service_time;   // ������ �ջ������ ���� �ð��� ����
        }
        guest[i].waiting_time = waiting - guest[i].arrival_time;    // ����ü ������ �ڽ��� �����ð��� ������ ���ð��� ����
    }
}
double avgtime(struct _bank guest[], int N){        
    double sum = 0;     // ������ ���ð� ������ ����
    for(int i = 0; i < N; i++){     // N�� �ݺ�
        sum += guest[i].waiting_time;       // ���ð��� ����
    }
    return sum / N;     // ��� ����Ͽ� ��ȯ
}


int main(){
    int n;      // ����� ���� ���� ����
    struct _bank guest[100];        // ����ü �迭 ����

    scanf("%d", &n);        // ����� �Է�

    for(int i = 0; i < n; i++){     // n�� ��ŭ �ݺ�
        scanf("%d %d %d", &guest[i].id, &guest[i].arrival_time, &guest[i].service_time);        // ���̵�, �����ð�, ���� �ð� �Է�
    }
    waitingtime(guest, n);      // �Լ� ȣ��

    printf("%.2lf", avgtime(guest, n)); // �Լ�ȣ���Ͽ� ����� ���

    return 0;
}