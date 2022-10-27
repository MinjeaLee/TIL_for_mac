#include <stdio.h>

int main(){
    int x[50] = {0}, n, count = 0;
    int *p;

    scanf("%d", &n);

    for(p = x; p < x + n; p++){
        scanf("%d", p);
    }

    for (p = x; p < x + n; p++)
    {
        count++;
        if(*p == 0){
            count--;
            break;
        }
    }

    printf("%d", count);
   
    return 0;
}