#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char name[8];
    int kor, eng, math;
}stu;

int main(){
    stu *arr;
    int n;
    double sum;

    scanf("%d", &n);
    getchar();

    arr = (stu *)malloc(sizeof(stu) * n);

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", &(arr + i)->name, &(arr + i)->kor, &(arr + i)->eng, &(arr + i)->math);
        getchar();
    }

    for(int i = 0; i < n; i++){
        printf("%s ", (arr + i)->name);
        sum = (arr + i)->kor + (arr + i)-> eng + (arr + i)->math;
        printf("%.1lf ", sum / 3);

        if((arr + i)->kor >= 90 || (arr + i)->eng >= 90 || (arr + i)->math >= 90){
            printf("GREAT ");
        }
        if((arr + i)->kor < 70 || (arr + i)->eng < 70 || (arr + i)->math < 70){
            printf("BAD ");
        }
        printf("\n");
    }
    
    free(arr);

    return 0;
}