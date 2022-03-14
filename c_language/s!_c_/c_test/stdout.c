#include <stdio.h>

// printf
int main()
{
    int a = 1234, b = 20020529;
    double pi = 3.141592653;

    printf("%6d\n", a);
    printf("%6d\n", b);
    printf("%.2f\n", pi);
    printf("%6.2f\n", pi);
    printf("%.3lf\n", pi);

    return 0;
}