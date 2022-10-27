#include <stdio.h>
#include <string.h>

struct hotel_info
{

    char name[31], meal_check;  // ȣ���̸�, ���� ����
    int grade;      // ���
    double reputation, distance;    // ����, �Ÿ�
};

int in_hotel_info(struct hotel_info *p)
{
    int num = 0;    // ȣ�� ���� ���� ���� ����

    for (;; p++)      // ���ѹݺ�, p�� �����ϸ鼭
    {
        scanf("%s", &p->name);      // �̸� �Է�
        if (strcmp(p->name, "0") == 0)
        {            // �̸��� 0�� �Էµɰ�� brea
            break;
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reputation, &p->distance, &p->meal_check);        // ������ ���� �Է�
        getchar();      // \n getchar

        num++;      // ȣ�ڼ� ++
    }
    return num;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info sort[100], *p_i, *p_j, tmp;       // ������ ����ü �迭, ����ü ������, ����ü�� �ٲܶ� �ʿ��� ����ü ���� ����
    double max_reputation = -1;     // ������ �ִ� ������ ���� �켱 -1�� �ʱ�ȭ
    int sort_index = 0; // ������ ����ü �迭�� �ε��� ��Ÿ�� ���� ����

    for(p_i = p; p_i < p + N; p_i++){       // p + n��ŭ �ݺ�
        if(p_i -> grade >= G && p_i -> distance <= D){  // ���ǰ� ��ġ�ϴ� ���
            sort[sort_index] = *p_i;        // sort�� append
            sort_index++;   //  sort �ε��� ++
        }
    }

    for(p_i = sort; p_i < sort + sort_index - 1; p_i++){    // �������� ���
        for(p_j = p_i + 1; p_j < sort + sort_index; p_j++){
            if(p_i->reputation < p_j->reputation){  // ������ �ڿ� ���� �� ū ���
                tmp = *p_i; // ����
                *p_i = *p_j;
                *p_j = tmp;
            }
            else if(p_i->reputation == p_j->reputation){    // ������ �������
                if(strcmp(p_i->name, p_j->name) > 0){       // ���������� ���� �� ����
                    tmp = *p_i;     // ����
                    *p_i = *p_j;
                    *p_j = tmp;
                }
            }
        }
    }


    for(p_i = sort; p_i < sort + sort_index; p_i++){    // sort�迭 ���
        printf("%s %d %.1lf %.1lf %c\n", p_i->name, p_i->grade, p_i->reputation, p_i->distance, p_i->meal_check);
    }


}
int main()
{
    struct hotel_info chart[100];   // ����ü �迭 ����
    int hotels_num, grade;  // ȣ�� ���� ����, ��� ���� ����
    double distance;    // �Ÿ� ���� ����

    hotels_num = in_hotel_info(chart);      // ȣ�� ���� -> �Լ� ȣ�� ��ȯ��

    scanf("%d %lf", &grade, &distance);     / ����(�Ÿ� ���) �Է�


    out_hotel_info(chart, hotels_num, grade, distance);     // �Լ� ȣ��

    return 0;
}