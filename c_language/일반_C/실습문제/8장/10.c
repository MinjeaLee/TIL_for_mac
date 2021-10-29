#include <stdio.h>

int n, i =1;
void die1(int x), die2(int x, int y), die3(int x, int y, int z);
    
void die1(int x){
    if(x >= 7){
        return;
    }
    return die2(x, 1);
}

void die2(int x, int y){
    if(y == 7){
        i++;
    }
    else{
        return die3(x, y, 1);
    }
}   

void die3(int x, int y, int z){
   for(int i = 1; i <= 6; i++){
        if (x + y + i == n){
            printf("%d %d %d\n", x, y, i);
        }
   }
   return die2(x, y + 1);
}


int main(){
    scanf("%d", &n);
    for(int h = 0; h < 6; h++){
        die1(i);
    }

    return 0;
}
