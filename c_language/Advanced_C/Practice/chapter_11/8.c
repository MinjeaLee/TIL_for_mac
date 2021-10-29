#include <stdio.h>

struct complex{
    double real, imaginary;
};

struct complex add(struct complex x, struct complex y){
    struct complex add_result;

    add_result.real = x.real + y.real;
    add_result.imaginary = x.imaginary + y.imaginary;

    return add_result;
}

int main(){
    struct complex x, y, result;

    scanf("%lf %lf\n%lf %lf", &x.real, &x.imaginary, &y.real, &y.imaginary);

    result = add(x, y);

    printf("%.1lf + %.1lfi", result.real, result.imaginary);

    return 0;
}