#include <stdio.h>

int is_prime(int x){
    int check = 1;
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            check = 0;
            break;
        }
    }
    return check;
}

int next_prime(int x){
    int result;
    for(int i = x + 1;;i++){
        if(is_prime(i)){
            result = i;
            break;
        }
    }
    return result;
}

int main(){
    int prime, num, a;
    scanf("%d %d", &prime, &num);
    for(int i = 0; i < num; i++){
        a = next_prime(prime);
        printf(" %d", a);
        prime = a;
    }

    return 0;
}