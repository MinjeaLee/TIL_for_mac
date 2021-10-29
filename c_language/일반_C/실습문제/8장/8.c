#include <stdio.h>

int func2(int x, int a, int b, int c){
    int result = a * x * x + b * x + c; 

    return result;
}

int main(){
    int num, fcoe1, fcoe2, fcoe3, gcoe1, gcoe2,gcoe3;
    scanf("%d", &num);
    scanf("%d %d %d", &fcoe1, &fcoe2, &fcoe3);
    scanf("%d %d %d", &gcoe1, &gcoe2, &gcoe3);
    printf("%d", func2(func2(num, fcoe1, fcoe2, fcoe3), gcoe1, gcoe2, gcoe3));

    return 0;
}