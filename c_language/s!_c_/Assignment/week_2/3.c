#include <stdio.h>

int main(){
    int x, y;
    char operator;

    scanf("%d %c %d", &x, &operator, &y);
    if(operator == '+'){
        printf("result: %d", x + y);
    }
    else{
        printf("result: %d", x - y);
    }
 
    return 0;
}