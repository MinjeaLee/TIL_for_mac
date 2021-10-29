#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    if (b > a){
        c = a;
        a = b;
        b = c;
        
    }
    if (b*b == a){
        printf("%d*%d=%d", b, b, a);
    }
    else{
        printf("none");
    }
    
    return 0;
}