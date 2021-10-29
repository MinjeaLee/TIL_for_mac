#include <stdio.h>

int main(){
    char a;
    int count_A = 0, count_a = 0, count_1 = 0, count_ = 0;
    while(1){
        scanf("%c", &a);
        if(a == '*'){
            break;
        }
        if('A' <= a && a <= 'Z'){
            count_A++;
        }
        else if('a' <= a && a <= 'z'){
            count_a++;
        }
        else if('0' <= a && a <= '9'){
            count_1 += a - '0';
        }
        else{
            count_++;
        }

    }
    printf("%d %d %d %d\n", count_A, count_a, count_1, count_);
   
    return 0;
}


