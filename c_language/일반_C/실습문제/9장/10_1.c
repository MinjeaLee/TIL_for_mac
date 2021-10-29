#include <stdio.h>

void gcdlcm(int a, int b, int* p_gcd, int* p_lcm){
    int tmp, n;
    int gcd_a, gcd_b;

    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    gcd_a = a;
    gcd_b = b;

    if(gcd_b == 0){
        *p_gcd = 0;
    }
    while (gcd_b != 0)
    {
        n = gcd_a % gcd_b;
        gcd_a = gcd_b;
        gcd_b = n;
    }
    *p_gcd = gcd_a;

    *p_lcm = a * b / *p_gcd;
}

int main(){
    int x, y, result_g, result_l;
    
    scanf("%d %d", &x, &y);
    gcdlcm(x, y, &result_g, &result_l);
    printf("%d %d", result_g, result_l);

    return 0;
}