#include <stdio.h>

int main(){
    int a,b,c,d,e,result;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    result = 0;
    if (a > 0){
        result += a;
    }
    if (b > 0){
        result += b;
    }
    if (c > 0){
        result += c;
    }
    if (d > 0){
        result += d;
    }
    if (e > 0){
        result += e;
    }

    printf("%d", result);
    return 0;
}