#include <stdio.h>

int main(){
    int money, a, b, c, tmp;
    scanf("%d", &money);
    
    for(a = 1; a < money / 900; a++){
        for(b = 2; b < money / 750; b+=2){
            for(c = 1; c < money / 200; c++){
                tmp = (900 * a) + (750 * b) + (200 * c);
            
                if(tmp != money){

                }
                else if(c > a && c > b){

                }
                else{
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
}