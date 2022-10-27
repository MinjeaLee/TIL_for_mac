#include <stdio.h>

struct time{
    int h, m, s;
};

int main(){
    struct time x, y, result;
    int minus;

    scanf("%d %d %d\n%d %d %d", &x.h, &x.m, &x.s, &y.h, &y.m, &y.s);

    minus = (y.h * 3600 + y.m * 60 + y.s) - (x.h * 3600 + x.m * 60 + x.s);

    result.h = minus / 3600;
    result.m = minus % 3600 / 60;
    result.s = minus % 3600 % 60 ;

    printf("%d %d %d", result.h, result.m, result.s);

    return 0;
}