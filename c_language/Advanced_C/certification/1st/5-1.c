#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct student {
    char name[21];
    int kor, eng, math;
}stu;

typedef struct average{
    double kor, eng, math;
}avg;

struct average calculate_average(struct student *st, int N){
    stu *p;
    struct average result;

    double total_kor = 0, total_eng = 0, total_math = 0;

    for(p = st; p < st + N; p++){
        total_kor += p->kor;
        total_eng += p->eng;
        total_math += p->math;
    }

    result.kor = total_kor / N;
    result.eng = total_eng / N;
    result.math = total_math / N;

    return result;
}


int main(){
    int n, kor_stu = 0, eng_stu = 0, math_stu = 0;
    stu list[50];
    avg Avg;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", &list[i].name, &list[i].kor, &list[i].eng, &list[i].math);
        getchar();
    }

    Avg = calculate_average(list, n);

    for(int i = 0; i < n; i++){
        if(Avg.kor > list[i].kor){
            kor_stu++;
        }
        if(Avg.eng > list[i].eng){
            eng_stu++;
        }
        if(Avg.math > list[i].math){
            math_stu++;
        }
    }

    printf("%.1lf %.1lf %.1lf\n", Avg.kor, Avg.eng, Avg.math);
    printf("%d %d %d", kor_stu, eng_stu, math_stu);

    return 0;
}
