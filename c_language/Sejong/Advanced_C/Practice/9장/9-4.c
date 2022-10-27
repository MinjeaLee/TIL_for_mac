#include <stdio.h>
void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int x[3];
    int *p_x1, *p_x2;

    for (p_x1 = x; p_x1 < x + 3; p_x1++)
    {
        scanf("%d", p_x1);
    }
    for (p_x1 = x; p_x1 < x + 2; p_x1++)
    {
        for(p_x2 = p_x1 + 1; p_x2 < x + 3; p_x2++){
            if(*p_x1 > *p_x2){
                swap(p_x1, p_x2);
            }
        }
    }
    
    printf("%d", *(x+1));

    return 0;
}