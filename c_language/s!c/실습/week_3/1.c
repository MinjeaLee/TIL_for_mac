#include <stdio.h>
#include <math.h>

typedef struct{
    int x, y;
}point;

int main(){
    
    point p1, p2;
    int d;

    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

    d = pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
    printf("%d", d);

    return 0;
}