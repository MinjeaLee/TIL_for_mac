#include <stdio.h>

int num_len(int x){
    int len = 0;
    while(x > 0){
        x /= 10;
        len++;
    }
    return len;
}

int main(){
    int n, len, pow = 1, one_num;
    char num[10][6] = { {"\0"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}};
    char decimal[4][4] = {{"\0"}, {"TEN"}, {"HUN"}, {"THO"}};

    scanf("%d", &n);

    len = num_len(n);
    
    for(int i = 0; i < len - 1; i++){
        pow *= 10;
    }

    while(n > 0){
        len--;
        one_num = n / pow;
        n %= pow;
        if(one_num){
            printf("%s %s ", num[one_num], decimal[len]);
        }
        pow /= 10;
    }

    return 0;
}