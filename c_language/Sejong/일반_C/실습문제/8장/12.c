#include <stdio.h>

void print_line(int x, int y, int z){
    for(int i = 0; i < x; i++){
        printf(" ");
    }
    for(int i = 0; i < y; i++){
        printf("*");
    }
    for(int i = 0; i < z; i++){
        printf(" ");
    }
    printf("\n");
}
int main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        print_line(((2 * num - 1) - (2 * i - 1))/2, (2 * i - 1), ((2 * num - 1) - (2 * i - 1))/2);
    }
}