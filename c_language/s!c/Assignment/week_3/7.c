#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct birth{
    char *name;
    char time[12];

}birth;

void swap(struct birth *a, struct birth *b){
    struct birth tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

}

int main(){
    birth list[100];
    int n;
    char year[5], month[3], day[3];

    scanf("%d",&n);
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%s %s-%s-%s", &list[i].name, year, month, day);
        getchar();
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(atoi(list[i].time) > atoi(list[j].time)){
                swap(&list[i], &list[j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s %s\n", list[i].name, list[i].time);
    }

    return 0;
}