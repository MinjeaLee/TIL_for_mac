#include <stdio.h>
#include <string.h>

typedef struct location{
    char *place;
    char start_time[20];
    char end_time[20];

}location;

typedef struct person{
    char *name;
    location *pl;
    int pl_num;

}person;

int main(){
    int n;
    person infected[100], uninfected[100];

    scanf("%d", &n);    // ºñ°¨¿°ÀÚ
    for(int i = 0; i < n; i++){
        scanf("%s %d", &uninfected[i].name, &uninfected[i].pl_num);
        getchar();
        for(int j = 0; j < uninfected[i].pl_num; i++) {
            scanf("%s %s/%s", &uninfected[i].pl->place, &uninfected[i].pl->start_time, &uninfected[i].pl->end_time);
            getchar();
        }
    }

    scanf("%d", &n);    // °¨¿°ÀÚ
    for(int i = 0; i < n; i++){
        scanf("%s %d", &infected[i].name, &infected[i].pl_num);
        getchar();
        for(int j = 0; j < infected[i].pl_num; i++) {
            scanf("%s %s/%s", &infected[i].pl->place, &infected[i].pl->start_time, &infected[i].pl->end_time);
            getchar();
        }
    }
 



    return 0;
}