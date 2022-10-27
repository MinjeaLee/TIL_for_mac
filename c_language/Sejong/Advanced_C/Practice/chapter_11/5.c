#include <stdio.h>

struct chart{
    char name[9];
    int x, y, z;
};


int main(){
    int n;
    double avg, sum;

    struct chart st[50], *p_st;

    scanf("%d", &n);
    getchar();
    for(p_st = st; p_st < st + n; p_st++){
        scanf("%s %d %d %d", &p_st -> name , &p_st -> x, &p_st -> y, &p_st -> z);
        getchar();
    }

    for(p_st = st; p_st < st + n; p_st++){
        sum = p_st -> x + p_st -> y + p_st -> z;
        avg = sum / 3;
        printf("%s %.1lf ", p_st -> name, avg);
        if(avg >= 90){
            printf("A\n");
        }
        else if(avg >= 80){
            printf("B\n");
        }
        else if(avg >= 70){
            printf("C\n");
        }
        else{
            printf("D\n");
        }
    }
    


    return 0;
}