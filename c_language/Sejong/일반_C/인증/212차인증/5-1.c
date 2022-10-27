#include <stdio.h>

int prime_number(int num);

int odd_number(int num);

int main(){
    int x[100], count = 0, num, numcount = 0, i, y[100];
    while(1){
        scanf("%d", &num);
        if(num < 0){
            break;
        }
        x[numcount] = num;
        numcount++;
    }
    for(i = 0; i < numcount; i++){
        if(prime_number(x[i]) || odd_number(x[i])){
            y[count] = x[i];
            count++;
        }
    }
    if(count == 0){
        printf("0");
    }
    else{
        for(i = count - 1; i >= 0; i--){
            printf("%d ", y[i]);
        }
    }

    
}

int prime_number(int num){
    int check = 1, i;
    for(i = 2 ; i < num; i++){
        if(num % i == 0){
            check = 0;
            break;
        }
    }
    return check;
}

int odd_number(int num){
    int check_num, check = 1;
    while(num > 0){
        check_num = num % 10;
        num /= 10;
        if(check_num % 2 == 0){
            check = 0;
            break;
        }
    }
    return check;
}