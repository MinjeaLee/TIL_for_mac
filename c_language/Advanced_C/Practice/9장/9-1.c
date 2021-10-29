#include <stdio.h>

int main(){
    int x, y, z;   
    int *px, *py, *pz, *tmp;

    scanf("%d %d %d", &x, &y, &z);

    px = &x; 
    py = &y; 
    pz = &z; 

    tmp = px;
    px = pz;
    pz = py;
    py = tmp;

    printf("%d %d %d", *px, *py, *pz);

    return 0;
}