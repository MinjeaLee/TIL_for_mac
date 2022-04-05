#include <stdio.h>

int main(){
    int n, sum, over_check = 0, num_x, num_y;
    char x[100000], y[100000];
    int result[100000];

    scanf("%d", &n);
    getchar();
    for(int i = 0; i< n; i++){
        scanf("%c", &x[i]);
    }
    getchar();
    for(int i = 0; i< n; i++){
        scanf("%c", &y[i]);
    }

    for(int i = n - 1; i >= 0; i--){
        num_x = x[i] - '0';
        num_y = y[i] - '0';
        if(over_check == 1){
            sum = num_x + num_y + 1;
            if(sum >= 10){
                over_check = 1;
            }
            else{
                over_check = 0;
            }
        }
        else{
            sum = num_x + num_y;
            if(sum >= 10){
                over_check = 1;
            }
            else{
                over_check = 0;
            }
        }
        if(i != 0){
            result[n - i - 1] = sum % 10;
        }
        else{
            result[n - i - 1] = sum % 10;
            result[n - i] = 1;
        }
    }
    if(over_check == 0){
        for(int i = n - 1; i >= 0; i--){
            printf("%d", result[i]);
        }
    }
    else{
        for(int i = n; i >= 0; i--){
            printf("%d", result[i]);
        }
    }
    

    return 0;
}