#include <stdio.h>

int main(){
    int n, m;
    scanf("%d", &n); // ����
    scanf("%d", &m); // 1�� ����
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

    
    scanf("%d", &m); // 2������
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