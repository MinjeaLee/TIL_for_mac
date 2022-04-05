#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{

    int id;
    double first, second;
    double total;

} stu;

int main()
{
    stu *list, tmp, *p, *pass, *second_list;
    int n, total_pass, first_pass = 0, pass_index = 0, end, second_pass = 0, second_index = 0;
    double first_cut, second_cut;

    scanf("%d", &n);
    total_pass = n * 8 / 10;
    list = (stu *)malloc(sizeof(stu) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %lf %lf", &list[i].id, &list[i].first, &list[i].second);
    }

    for (int i = 0; i < n; i++)
    {
        list[i].total = list[i].first * 0.4 + list[i].second * 0.6;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (p = list; p < list + n - 1 - i; p++)
        {
            if (p->total < (p + 1)->total)
            {
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }

    first_cut = list[n * 6 / 10 - 1].total;

    for (int i = 0; i < n; i++)
    {
        if (first_cut <= list[i].total)
        {
            first_pass++;
        }
    }

    pass = (stu *)malloc(sizeof(stu) * first_pass);

    for (int i = 0; i < n; i++)
    {
        if (first_cut <= list[i].total)
        {
            pass[pass_index] = list[i];
            pass_index++;
            end = i;
        }
    }

    if (first_pass < n * 8 / 10)
    {

        second_list = (stu *)malloc(sizeof(stu) * (n - first_pass));
        for (int i = end + 1; i < n; i++)
        {
            second_list[second_index++] = list[i];
        }
        for (int i = 0; i < n - first_pass - 1; i++)
        {
            for (p = second_list; p < second_list + n - first_pass - 1 - i; p++)
            {
                if (p->second < (p + 1)->second)
                {
                    tmp = *p;
                    *p = *(p + 1);
                    *(p + 1) = tmp;
                }
            }
        }

        second_cut = second_list[total_pass - first_pass - 1].second;

        for (int i = 0; i < second_index; i++)
        {
            if (second_cut <= second_list[i].second)
            {
                second_pass++;
            }
        }
        pass = (stu *)realloc(pass, sizeof(stu) * (first_pass + second_pass));

        for (int i = 0; i < second_index; i++)
        {
            if (second_list[i].second >= second_cut)
            {
                pass[pass_index] = second_list[i];
                pass_index++;
            }
        }
        free(second_list);
    }

    for (int i = 0; i < pass_index - 1; i++)
    {
        for (p = pass; p < pass + pass_index - 1 - i; p++)
        {
            if (p->id > (p + 1)->id)
            {
                tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }

    for (int i = 0; i < pass_index; i++)
    {
        printf("%d\n", pass[i].id);
    }
    free(list);
    free(pass);

    return 0;
}