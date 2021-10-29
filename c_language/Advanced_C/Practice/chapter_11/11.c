#include <stdio.h>

struct chart{
    char name[10];
    int score;
};

int main(){
    struct chart st[5];

    int min = 101;

    for(int i = 0; i < 5; i++){
        scanf("%s %d", &st[i].name, &st[i].score);
        getchar();
    }
    for(int i = 0; i < 5; i++){
        if(min > st[i].score){
            min = st[i].score;
        }
    }
    for(int i = 0; i < 5; i++){
        if(min == st[i].score){
            printf("%s %d", st[i].name, st[i].score);
            break;
        }
    }


    return 0;
}