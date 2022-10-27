#include <stdio.h>

int main(){
    int num, total = 0;
    while (1)
    {
        scanf("%d", &num);
        total += num;
        if (num == 0){
            break;
        }
    }
    printf("%d", total);

    return 0;
}