#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct complex
{
    double real, imag;
};

struct complex add(struct complex *x, struct complex *y);
struct complex sub(struct complex *x, struct complex *y);
void abs_val(struct complex *p1, struct complex *p2, struct complex *p3);

int main(void)
{
    struct complex x, y, z, ADD, SUB;

    scanf("%lf %lf", &x.real, &x.imag);
    scanf("%lf %lf", &y.real, &y.imag);
    scanf("%lf %lf", &z.real, &z.imag);

    abs_val(&x, &y, &z);
    ADD = add(&x, &y);
    SUB = sub(&x, &y);

    printf("%.1lf%+.1lfi\n", ADD.real, ADD.imag);
    printf("%.1lf%+.1lfi\n", SUB.real, SUB.imag);

    return 0;
}

struct complex add(struct complex *x, struct complex *y)
{
    struct complex ADD;
    ADD.real = x->real + y->real;
    ADD.imag = x->imag + y->imag;
    return ADD;
}

struct complex sub(struct complex *x, struct complex *y)
{
    struct complex SUB;
    SUB.real = x->real - y->real;
    SUB.imag = x->imag - y->imag;
    return SUB;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3)
{
    double fir = 0.0, sec = 0.0, thr = 0.0, max = 0.0, min = 0.0;
    struct complex tmp;

    fir = p1->real * p1->real + p1->imag * p1->imag;
    sec = p2->real * p2->real + p2->imag * p2->imag;
    thr = p3->real * p3->real + p3->imag * p3->imag;

    if (fir > sec)
    {
        max = fir;
        min = sec;
    }
    else
    {
        max = sec;
        min = fir;

        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }

    if (max < thr)
    {
        tmp = *p1;
        *p1 = *p3;
        *p3 = tmp;
    }
    if (min > thr)
    {
        tmp = *p2;
        *p2 = *p3;
        *p3 = tmp;
    }
}