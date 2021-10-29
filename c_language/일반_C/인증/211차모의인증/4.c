#include <stdio.h>

int main(){
    int a,b,c,d;
    int i, j;
    scanf("%d %d",&a,&b);
    scanf("%d %d", &c, &d);
    for(j = c; j <=d; j++){
        for(i = a; i<= b; i++){
            printf(" %d", i*j);
        }
        printf("\n");
    }


    return 0;
}