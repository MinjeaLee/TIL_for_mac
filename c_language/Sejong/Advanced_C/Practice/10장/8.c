#include <stdio.h>
#include <string.h>

int main(){
    char x[51], y[51];

    scanf("%s %s", x, y);

    if(strcmp(x, y) < 0){
        printf("%s%s", y, x);
    }
    else{
        printf("%s%s", x, y);
    }

    return 0;
}
