#include <stdio.h>
#include <string.h>

typedef struct sutduent{

    char name[10], grade;       // �л��̸�, ���
    int id;                 // �й�

}stu;

int main(){

    stu chart[5];   // 5�� ����ü �迭 ����
    char check_name[10];            // Ȯ���� �л� �̸� ���� ���ڿ� ����

    for(int i = 0; i < 5; i++){ // 5�� �ݺ�
        scanf("%s %d %c", &chart[i].name, &chart[i].id, &chart[i].grade);       // �̸� �й� ���� �Է�
        getchar();      // \n getchar
    }
    scanf("%s", check_name);        // Ȯ���� �л� �̸� 

    for(int i = 0; i < 5; i++){     // �迭Ȯ��
        if(strcmp(check_name, chart[i].name) == 0){     // �Է¹��� �̸��� ���� ���� �ִٸ�
            printf(" %d %c", chart[i].id, chart[i].grade);      // �л� ���� ���
        }
    }

    return 0;
}