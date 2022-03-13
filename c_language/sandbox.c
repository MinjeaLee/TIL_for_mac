#include <stdio.h>
#include <stdlib.h>

struct date
{
    int idx;
    int year, month, day;
    int diff;
};

int calc_day(int y, int m, int d)
{
    int fixed[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, res = 0;
    res = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
    if (!(y % 4) && y % 100 || !(y % 400)) // 윤년 계산
        fixed[1]++;
    for (i = 0; i < m - 1; i++)
    {
        res += fixed[i];
    }
    res += d;
    return res;
}

int date_input(struct date *p)
{
    int i;
    for (i = 0;; i++)
    {
        scanf("%d/", &p[i].year);
        if (p[i].year == 0)
            break;
        scanf("%d/%d", &p[i].month, &p[i].day);
    }
    return i;
}

void date_print(struct date *p, int n)
{
    p[0].diff = 0;
    for (int i = 1; i < n; i++)
    {
        p[i].diff = calc_day(p[i].year, p[i].month, p[i].day) - calc_day(p[0].year, p[0].month, p[0].day);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (abs(p[j].diff) > abs(p[j + 1].diff))
            {
                int tmpy, tmpm, tmpd, tmpdiff;
                tmpy = p[j].year;
                tmpm = p[j].month;
                tmpd = p[j].day;
                tmpdiff = p[j].diff;
                p[j].year = p[j + 1].year;
                p[j].month = p[j + 1].month;
                p[j].day = p[j + 1].day;
                p[j].diff = p[j + 1].diff;
                p[j + 1].year = tmpy;
                p[j + 1].month = tmpm;
                p[j + 1].day = tmpd;
                p[j + 1].diff = tmpdiff;
            }
            else if (abs(p[j].diff) == abs(p[j + 1].diff))
            {
                if (p[j].idx > p[j + 1].idx)
                {
                    int tmpy, tmpm, tmpd, tmpdiff;
                    tmpy = p[j].year;
                    tmpm = p[j].month;
                    tmpd = p[j].day;
                    tmpdiff = p[j].diff;
                    p[j].year = p[j + 1].year;
                    p[j].month = p[j + 1].month;
                    p[j].day = p[j + 1].day;
                    p[j].diff = p[j + 1].diff;
                    p[j + 1].year = tmpy;
                    p[j + 1].month = tmpm;
                    p[j + 1].day = tmpd;
                    p[j + 1].diff = tmpdiff;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d/%02d/%02d", p[i].year, p[i].month, p[i].day); //p[i].diff > 0 ? " +" : " ", p[i].diff);
        if(p[i].diff == 0){
            printf("  %d\n", p[i].diff);
        }
        else if(p[i].diff > 0){
            printf(" +%d\n", p[i].diff);
        }
        else{
            printf(" %d\n", p[i].diff);
        }
    }
}

int main()
{
    struct date tmp[105];
    int k;
    k = date_input(tmp);
    date_print(tmp, k);
}