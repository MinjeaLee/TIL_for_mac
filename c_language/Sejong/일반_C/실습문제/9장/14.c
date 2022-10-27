#include <stdio.h>

int add_to_k(int* s, int* e){
    int* p_x;
    int result = 0;
    for(p_x = s; p_x <= e; p_x++){
        result += *p_x;
    }
    return result;
}

int main(){
    int x[100],n, total = 0;
    int *p,*p_s, *p_e;

    scanf("%d", &n);
    for(p = x; p < x + n; p++){
        scanf("%d", p);
    }
    
    for(p_e = x; p_e < x + n; p_e++){
        total += add_to_k(x, p_e);
    }

    printf("%d", total);


    return 0;
}