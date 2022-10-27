#include <stdio.h>

int main(){
    int x[10], max = 0;
    int i, len_x = sizeof(x)/sizeof(int);
    for(i = 0;i < len_x; i++){
        scanf("%d", &x[i]);
        if(max < x[i]){
            max = x[i];
        }
    }    
    printf("%d", max);
    return 0;
}