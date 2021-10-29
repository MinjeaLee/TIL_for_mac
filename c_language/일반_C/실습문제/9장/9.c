#include <stdio.h>

int mid(int *x){
    int *p_x, *p_y;
    int temp;
    for(p_x = x; p_x < x + 2; p_x++){
        for(p_y = p_x + 1; p_y < x + 3; p_y++){
            if(*p_x > *p_y){
                temp = *p_x;
                *p_x = *p_y;
                *p_y = temp;
            }
        }
    }
    return *(x + 1);

}

int main(){
    int x[3];
    int *p;

    for(p = x; p < x + 3; p++){
        scanf("%d", p);
    }

    printf("%d", mid(x));

    return 0;
}
