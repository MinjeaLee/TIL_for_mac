#include <stdio.h>
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
    int n;
    char _name[100];
    birth list[100], *p, *q;

    scanf("%d", &n);
    getchar();

    for(p = list; p < list + n; p++){
        scanf("%s %s", &p->name, &p->time);
    }

    for(p = list; p < list + n - 1; p++){
        for(q = p + 1; q < list + n; q++){
            if(strcmp(p->time, q->time) > 0){
                swap(p ,q);
            }
            else if(strcmp(p->time, q->time) == 0){
                if(strcmp(p->name, q->name) > 0){
                    swap(p ,q);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s %s\n", list[i].name, list[i].time);
    }

    

    return 0;
}