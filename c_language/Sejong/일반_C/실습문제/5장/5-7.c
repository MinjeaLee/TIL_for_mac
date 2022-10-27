#include <stdio.h>

int main(){
    int n, m;
    scanf("%d", &n); // 정답
    scanf("%d", &m); // 1차 추측
    if (m > n){
        printf("DOWN\n");
    }
    else if(m < n){
        printf("UP\n");
    }
    else{
        printf("RIGHT\n");
        return 0;
    }

    
    scanf("%d", &m); // 2차추측
    if (m > n){
        printf("DOWN\n");
    }
    else if(m < n){
        printf("UP\n");
    }
    else{
        printf("RIGHT\n");
        return 0;
    }

    return 0;
}