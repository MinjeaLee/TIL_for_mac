#include <stdio.h>

void gcdlcm(int x, int y, int *gcd_result, int* lcm_reslt){
    int tmp, n, gcd_x, gcd_y;

    if(x < y){
        tmp = x;
        x = y;
        y = tmp;
    }
    gcd_x = x;
    gcd_y = y;

    if(gcd_y == 0){
        *gcd_result = 0;
    }
    while (gcd_y != 0)
    {
        n = gcd_x % gcd_y;
        gcd_x = gcd_y;
        gcd_y = n;
    }
    *gcd_result = gcd_x;

    *lcm_reslt = 1;
    for(int i = 2; i <= x; i++){
        if(x % i == 0 && y % i == 0){
            *lcm_reslt = i;
            break;
        }
    }
}


int main(){
    int x, y, result_gcd, result_lcm;

    scanf("%d %d", &x, &y);

    gcdlcm(x, y, &result_gcd, &result_lcm);

    printf("%d %d", result_gcd, result_lcm);

    return 0;
}