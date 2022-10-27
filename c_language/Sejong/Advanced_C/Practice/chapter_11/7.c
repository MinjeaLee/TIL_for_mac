#include <stdio.h>

struct chart{
    int score, rangking;
};

int main(){
    struct chart st[10];

    for(int i = 0; i < 10; i++){
        scanf("%d", &st[i].score);
        st[i].rangking = 1;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(st[i].score < st[j].score){
                st[i].rangking++;
            }
        }
    }
    for(int i = 0; i< 10; i++){
        if(st[i].rangking == 3){
            printf("%d", st[i].score);
        }
    }

    for(int i = 0; i< 10; i++){
        if(st[i].rangking == 7){
            printf("%d", st[i].score);
        }
    }

    return 0;
}