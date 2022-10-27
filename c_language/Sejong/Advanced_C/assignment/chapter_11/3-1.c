#include <stdio.h>
#include <string.h>

struct hotel_info       
{

    char name[31], meal_check;      // ȣ���̸�, ���� ����
    int grade;      // ���
    double reputation, distance;    // ����, �Ÿ�
};

int in_hotel_info(struct hotel_info *p)
{
    int num = 0;        // ȣ�� ���� ���� ���� ����

    for (;; p++)        // ���ѹݺ�, p�� �����ϸ鼭
    {
        scanf("%s", &p->name);  // �̸� �Է�
        if (strcmp(p->name, "0") == 0)  // �̸��� 0�� �Էµɰ�� break
        {
            break;
        }
        scanf("%d %lf %lf %c", &p->grade, &p->reputation, & p->distance, &p->meal_check);       // ������ ���� �Է�
        getchar();  // \n getchar

        num++;  // ȣ�ڼ� ++
    }
    return num;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D)
{
    struct hotel_info *p_struct, max; // ����ü ������, ���� ū ���� ���� ����ü ������ ����ü ���� ����
    double max_reputation = -1; // ������ �ִ� ������ ���� �켱 -1�� �ʱ�ȭ
    int fast_check;     // �̸� ������ ������ �� ����� ���� ���� ����

    for (p_struct = p; p_struct < p + N; p_struct++)        // �ݺ�
    {
        if (p_struct->grade >= G && p_struct->distance <= D)        // ������ ��ġ�ϴ� ���
        {
            if (p_struct->reputation > max_reputation)      // ���� ��
            {
                max_reputation = p_struct->reputation;      // �ִ� ���� ���� �ٲ�
                memcpy(&max, p_struct, sizeof(struct hotel_info)); // ����ü ����
            }
            if (p_struct->reputation == max_reputation)     // ������ ���� ���
            {
                fast_check = strcmp(p_struct->name, max.name);  // ���ڿ� �񱳰� ����
                if (fast_check < 0)     // ������ max�� ����� �̸��� ���������� �ڿ� �ִ� ���
                {
                    memcpy(&max, p_struct, sizeof(struct hotel_info));  // ����ü ����
                }
            }
        }
    }
    printf("%s %d %.1lf %.1lf %c", max.name, max.grade, max.reputation, max.distance, max.meal_check);      // ��� ���
}
int main()
{
    struct hotel_info chart[100];       // ����ü �迭 ����
    int hotels_num, grade;          // ȣ�� ���� ����, ��� ���� ����
    double distance;        // �Ÿ� ���� ����

    hotels_num = in_hotel_info(chart);      // ȣ�� ���� -> �Լ� ȣ�� ��ȯ��

    scanf("%d %lf", &grade, &distance);     // ����(�Ÿ� ���) �Է�

    out_hotel_info(chart, hotels_num, grade, distance);     // �Լ� ȣ��

    return 0;
}