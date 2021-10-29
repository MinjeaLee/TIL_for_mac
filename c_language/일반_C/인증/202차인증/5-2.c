#include <stdio.h>

int del_dupnum(int num);

int main(){
    printf("%d", del_dupnum(23303843));

    return 0;
}

int del_dupnum(int num){
    int tmp = 0, count = 0;
    int x[10], check, i, j, check_du, result = 0;
    while(num > 0){
        tmp *= 10;
        tmp += (num % 10);
        num /= 10;
    }
    num = tmp;
    while(num > 0){
        check = num % 10;
        x[count] = check;
        num /= 10;
        count++;
    }
    for(i = 0; i < count - 1; i++){
        for(j = i  + 1; j < count; j++){
            if(x[i] == x[j]){
                x[j] = -1;
            }
        }
    }
    
    printf("\n");
    for(i = 0; i < count; i++){
        if(x[i] != -1){
            result *= 10;
            result += x[i];
        }
    }

    return result;
