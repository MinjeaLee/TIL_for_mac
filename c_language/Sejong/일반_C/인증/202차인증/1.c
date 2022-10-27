#include <stdio.h>

int main(){
    int n, x[100], i, max = -1, dis, max_num = -1;
    int nummax[100], count = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    } 
    for(i = 0; i < n - 1; i++){
        if(x[n - 1] - x[i] > 0){
            dis = x[n - 1] - x[i];
            if(dis > max){
                max = dis;
                max_num = x[i];
            }
            else if(dis == max){
                if(max_num < x[i]){
                    max_num = x[i];
                }
            }
        }
        else{
            dis = -1 * (x[n - 1] - x[i]);
            if(dis > max){
                max = dis;
                max_num = x[i];
            }
            else if(dis == max){
                if(max_num < x[i]){
                    max_num = x[i];
                }
            }
        }
    }

    printf("%d", max_num);

    return 0;
}