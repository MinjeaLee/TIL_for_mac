#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, max = 0, count = 0, max_count = 0, max_num = 0;
    scanf("%d", &n);
    while(n != 0){
        if(n % 2 == 1){
            if(count > max_count){
                max_count = count;
                max_num = n;
            }
            count = 0;
        }
        count++;
        scanf("%d", &n);
    }
    if(max_count == 0){
        printf("none");
    }
    else{
        printf("%d %d", max_count, max_num);
    }
    
    return 0;
}