#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int gcd(int x, int y) {
    int tmp;
    if(x < y){
        tmp = x;
        x = y;
        y = tmp;
    }
    if(y == 0){
        return 0;
    }
    if(x % y == 0){
        return y;
    }
    else{
        return gcd(y, x % y);
    }

}

int main(){
    int x, y, result;

    scanf("%d %d",&x,&y);
    result = gcd(x,y);
    printf("%d", result);
    return 0;
}