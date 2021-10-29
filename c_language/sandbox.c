#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int a;
    
    scanf("%d", &a);

    if(a == 0){
        printf("0");
    }
    else{
        printf("%d", a);
    }


    return 0;
}