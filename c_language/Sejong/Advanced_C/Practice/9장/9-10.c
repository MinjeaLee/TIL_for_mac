#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void gcdlcm(int a, int b, int *p_gcd, int *p_lcm){
    int n, gcd, lcm, lcm_a, lcm_b;

    lcm_a = a;
    lcm_b = b;

    if(a < b){
        swap(&a, &b);
    }
    if(b == 0){
        gcd = 0;
    }
    else{
        while(b != 0){
            n = a % b;
            a = b;
            b = n;
        }
        gcd = a;
    }
    lcm = lcm_a * lcm_b / gcd;

    *p_gcd = gcd;
    *p_lcm = lcm;
}

int main(){
    int x, y, gcd, lcm;

    scanf("%d %d", &x, &y);
    gcdlcm(x, y, &gcd, &lcm);

    printf("%d %d", gcd, lcm);
        
    return 0;
}