#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sutduent{

    char name[10], grade; // �л��̸�, ���
    char id[11], year[5];// �й�, ���г⵵ 
    
}stu;

int main(){
    stu chart[5], check_stu;         // 5�� ����ü �迭 ����, Ȯ���� �л� ������ ���� ����ü ����
    char check_name[10];        // Ȯ���� �л� �̸� ���� ���ڿ� ����
    int check = 0;                  // �л��� �ִ� �� �������� üũ�� ���� ����


    for(int i = 0; i < 5; i++){         // 5�� �ݺ� 
        scanf("%s %s %c", &chart[i].name, &chart[i].id, &chart[i].grade);   // �л����� �Է�
        strncpy(chart[i].year, chart[i].id, 4);     // ���г⵵�� �й� �տ��� 4����
        chart[i].year[4] = '\0';    // ������ �ε����� \0����
        getchar();      // \n getchar
    }
    scanf("%s", check_name);    // Ȯ���� �л� �̸�

    for(int i = 0; i < 5; i++){     // �迭Ȯ��
        if(strcmp(check_name, chart[i].name) == 0){     //Ȯ���� �л��� ���
            check_stu = chart[i];                       // ����ü ����
            break;                  
        }
    }
    

    for(int i = 0; i < 5; i++){         // 5�� �ݺ�
        if(strcmp(check_stu.year, chart[i].year) == 0 && check_stu.grade == chart[i].grade && strcmp(check_stu.name,chart[i].name) != 0){   // ���г⵵�� ����, ������ ������, Ȯ���� ����� �̸��� �ٸ� ��� Ȯ��
            printf("%s ", chart[i].name);       // �̸� ���
            check = 1;      // ��쿡 �´� ��찡 �����Ƿ� check������ 1��
        }
    }   
    if(check == 0){     // check�� 0�̸�
        printf("0");        // 0���
    }
    printf("\n");       // �ٹٲ�
    printf("%s %d", check_stu.year, atoi(check_stu.year) % 131); // Ȯ���� �л� ���г⵵�� 131�� ���� ������ ���
    
    return 0;
}