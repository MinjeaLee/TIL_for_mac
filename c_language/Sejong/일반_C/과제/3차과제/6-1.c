#include <stdio.h>

int main(){
    int num, i, j;      // �Է� ���� ��, for�� ���� ����
    scanf("%d", &num);      // �� �Է�
    for(i = 1; i <= num ; i++){     // num�� �ݺ�
        for(j = 0; j < num - i; j++){       // num - i ��ŭ ��ĭ ���
            printf(" ");   
        }
        if(i == 1 || i == num){     // 1���϶��� ������ ���϶��� X���� ��� �ǹǷ�
            for(j = 0; j < 2 * i -1; j++){      // 2N - 1���� ��ŭ �� ���
                printf("X");
            }
        }
        else{
            printf("X");        // ���� X���
            for(j = 0; j < 2 * (i - 1) - 1; j++){   // 2(n-1)-1 ���� ��ŭ O���
                printf("O");
            }
            printf("X");       // ���� X���
        }
        printf("\n");       // �ٹٲ�.
        
    }
    return 0;
}