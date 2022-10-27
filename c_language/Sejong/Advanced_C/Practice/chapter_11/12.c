#include <stdio.h>
struct chart
{
    char name[10];
    int x, y, z;
    double avg;
};

void swap(struct chart *x, struct chart *y){
    struct chart tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;

}

void read_data(struct chart st[]){
    for(int i = 0; i < 10; i++){
        scanf("%s %d %d %d", &st[i].name, &st[i].x, &st[i].y, &st[i].z);
        getchar();
    }
}

void cal_avg(struct chart st[]){
    double sum;
    for(int i = 0; i < 10; i++){
        sum = st[i].x + st[i].y +st[i].z;
        st[i].avg  = sum / 3;
    }
}

void sort(struct chart st[]){
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 10; j++){
            if(st[i].avg < st[j].avg){
                swap(&st[i], &st[j]);
            }
        }
    }
}
void print_score(struct chart st[]){
    printf("%s %.2lf\n", st[0].name, st[0].avg);
    printf("%s %.2lf\n", st[9].name, st[9].avg);
    for(int i = 7; i < 10; i++){
        printf("%s %.2lf\n", st[i].name, st[i].avg);
    }
}


int main(){
    struct chart st[10];

    read_data(st);
    cal_avg(st);
    sort(st);
    print_score(st);

    return 0;
}