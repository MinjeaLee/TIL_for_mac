#include <stdio.h>

struct chart{
    char name[10];
    int score;
};

int main(){
    struct chart st[5];
    double avg, sum;

    for(int i = 0; i < 5; i++){
        scanf("%s %d", &st[i].name, & st[i].score);
        getchar();
    }

    for(int i = 0; i < 5; i++){
        sum += st[i].score;
    }
    avg = sum / 5;

    for(int i = 0; i < 5; i++){
        if(st[i].score < avg){
            printf("%s\n", st[i].name);
        }
    }

    return 0;
}