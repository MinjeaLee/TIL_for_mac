#include <stdio.h>

int print_triangle(int x){
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int a;
    while(1){
        scanf("%d", &a);
        if(a <= 0){
            break;
        }
        print_triangle(a);
    }
    return 0;
}
