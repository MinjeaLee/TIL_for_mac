#include <stdio.h>

int main(){
    int num, a, b, c, result;
    scanf("%d", &num);
    for(a = 1; a <= 6 ; a++){
        for (b = 1; b <= 6; b++){
            for (c = 1; c <= 6; c++){
                result = num;
                result -= (a+b+c);
                if(result == 0){
                    printf("%d %d %d\n", a,b,c);
                }
            }
        }
    }
    return 0;
}