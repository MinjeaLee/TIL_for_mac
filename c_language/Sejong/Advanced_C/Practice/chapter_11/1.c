#include <stdio.h>

struct vecter{
    int x, y, z;
};


int main(){
    struct vecter v1, v2, v3;
    int inner_product;

    scanf("%d %d %d\n%d %d %d", &v1.x, &v1.y, &v1.z, &v2.x, &v2.y, &v2.z);

    v3.x = v1.x * v2.x;
    v3.y = v1.y * v2.y;
    v3.z = v1.z * v2.z;

    inner_product = v3.x + v3.y + v3.z;

    printf("%d %d %d\n%d", v3.x, v3.y, v3.z, inner_product);

    return 0;
}