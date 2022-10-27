#include <stdio.h>

void strcopy(char* x, char* y){
    char *p_x;
    
    for(p_x = x; p_x < x + 6; p_x++){
        *(y + (p_x - x)) = *p_x;
    }
}


int main(){
    char a[6], b[6] = {'1', };
    char *p;
    for (p = a; p < a + 6; p++){
        scanf("%c", p);
    }
    
    strcopy(a, b);

    for(p = b; p < b + 6; p++){
        printf("%c", *p);
    }

    return 0;
}