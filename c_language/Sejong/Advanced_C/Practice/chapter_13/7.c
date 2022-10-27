#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int main(){
    int num_a;
    int x, y;
    void *v_p;
    int (*fp)(int, int);

    scanf("%d", &num_a);
    v_p = &num_a;
    printf("%d\n", *(int *)v_p);

    scanf("%d %d", &x, &y);
    fp = add;
    printf("%d\n", fp(x, y));

    return 0;
}