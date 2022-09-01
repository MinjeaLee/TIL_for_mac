#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int a = 10;
    int *ptr, **dptr;

    ptr = &a;
    dptr = &ptr;


    return 0;
}