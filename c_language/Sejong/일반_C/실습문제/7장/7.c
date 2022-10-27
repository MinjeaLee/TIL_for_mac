#include <stdio.h>

int main(){
    int x[10], num[10], count[10], i, num_check, num_count = 0, j, overlap;
    for(i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 10; i++){
        num_check = 0;
        for(j = 0; j < num_count; j++){
            if(x[i] == num[j]){
                num_check = 1;
                break;
            }
        }
        if(num_check == 0){
            num[num_count] = x[i];
            num_count++;
        }
    }
    for(i = 0; i < num_count; i++){
        overlap = 0;
        for(j = 0; j < 10; j++){
            if(num[i] == x[j]){
                overlap++;
            }
        }
        count[i] = overlap;
    }
    for(i = 0; i < num_count; i++){
        printf("%d %d\n", num[i], count[i]);
    }
    return 0;
}
    