#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int input(int *p){
    int *p_i;
    int count = 0;
    int tmp;

    for(p_i = p; ;p_i++){

        scanf("%d", &tmp);
        if(tmp == -1){
            break;
        }
        *p_i = tmp;
        count++;
    }
    return count;
}

int *sel_next(int *p, int N, int M){
    int *p_i, *result;
    int sum = 0;

    for(p_i = p + M; p_i < p + N; p_i++){
        sum += *p_i;
        if(sum > 10){
            result = p_i - 1;
            break;
        }
        result = p_i;
    }
    
    return result;
}

int number(int *p, int *q){
    int result = 0;
    int *p_i;

    for(p_i = p; p_i <= q; p_i++){
        result *= 10;
        result += *p_i;
    }

    return result;
}



int main(){
    int x[100], M;
    int count;
    int num;

    count = input(x);
    scanf("%d", &M);

    num = number(x + M, sel_next(x, count, M));
    
    printf("%d", num);
    

    return 0;
}