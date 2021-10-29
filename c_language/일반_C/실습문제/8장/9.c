#include <stdio.h>
#include <limits.h>

int max1 = INT_MIN, max2;

void update_max(int x){
    if(x > max1){
        max2 = max1;
        max1 = x;
    }
    else if(x > max2){
        max2 = x;
    }
}

int main(){
    int num;
    while(1){
        scanf("%d", &num);
        if(num == 0){
            break;
        }
        update_max(num);
    }
    printf("%d %d", max1, max2);

    return 0;
}