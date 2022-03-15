#include <stdio.h>

typedef struct student{
    char name[10];
    int x, y, z;
    double avg;
}stu;

void read_data(struct student list[]){
    struct student *p;
    for(p = list; p < list + 10; p++){
        scanf("%s %d %d %d", &p->name, &p->x, &p->y, &p->z);
    }
}

void cal_avg(struct student list[]){
    struct student *p;
    double sum = 0;

    for(p = list; p < list + 10; p++){
        sum = (p->x + p->y + p->z);
        p->avg = sum / 3;
    }
}

void sort(struct student list[]){
    struct student *p_i, *p_j, tmp;

    for(p_i = list; p_i < list + 9; p_i++){
        for(p_j = p_i + 1; p_j < list + 10; p_j++){
            if(p_i->avg < p_j->avg){
                tmp = *p_j;
                *p_j = *p_i;
                *p_i = tmp;
            }
        }
    }
}

void printf_score(struct student list[]){

    printf("%s %.2lf\n", list[0].name, list[0].avg);
    printf("%s %.2lf\n", list[9].name, list[9].avg);
    for(int i = 7; i < 10; i++){
        printf("%s %.2lf\n", list[i].name, list[i].avg);
    }
}

int main(){
    stu list[10];

    read_data(list);
    cal_avg(list);
    sort(list);
    printf_score(list);

    return 0;
}