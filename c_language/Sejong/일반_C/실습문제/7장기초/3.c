#include <stdio.h>

int main(){
    int x[10], y[10];
    int i;
    for(i = 0; i < sizeof(x)/sizeof(int); i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < sizeof(y)/sizeof(int); i++){
        scanf("%d", &y[i]);
    }
    for(i = 0; i < sizeof(x)/sizeof(int); i++){
        printf(" %d", x[i]+y[i]);
    }

    return 0;
}