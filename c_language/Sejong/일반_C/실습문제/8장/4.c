#include <stdio.h>

void print_row1(int x){
    for(int i = 0; i < x; i++){
        printf("%d", x);
    }
    printf("\n");
}

void print_row2(int x){
    for(int i = 0; i < x - 2; i++){
        printf("%d", x);
        for(int j = 0; j < x - 2; j++){
            printf(" ");
        }
        printf("%d\n", x);
    }
}

int main(){
    int a;
    scanf("%d", &a);
    print_row1(a);
    print_row2(a);
    print_row1(a);

    return 0;
}