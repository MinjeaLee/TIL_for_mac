#include <stdio.h>

int main(){
    int a1, a2, a3;
    int c1, c2, c3;
    int count_s = 0, count_b = 0;
    scanf("%d %d %d", &a1, &a2, &a3);
    scanf("%d %d %d", &c1, &c2, &c3);
    if (a1 == c1){
        count_s++;
    }
    if(a2 == c2){
        count_s++;
    }
    if(a3 == c3){
        count_s++;
    }
    if(a1 != c1){
        if(a1 == c2 || a1 == c3){
            count_b++;
        }
    }
    if(a2 != c2){
        if(a2 == c3 || a2 == c1){
            count_b++;
        }
    }
    if(a3 != c3){
        if(a3 == c1 || a3 == c2){
            count_b++;
        }
    }
    
    printf("%dS%dB", count_s, count_b);

    return 0;
}