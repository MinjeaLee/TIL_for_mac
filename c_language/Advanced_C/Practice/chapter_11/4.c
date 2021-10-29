#include <stdio.h>

struct chart{
    char name[20];
    int x, y, z;
};

int main(){
    int n;
    double avg, sum;

    struct chart st[20];

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", &st[i].name, &st[i].x, &st[i].y, &st[i].z);
        getchar();
    }

    for(int i = 0; i < n; i++){
        sum = st[i].x + st[i].y +st[i].z;
        avg = sum / 3;
        printf("%s %.1lf ", st[i].name, avg);
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
            printf("F\n");
        }
    }

    return 0;
}