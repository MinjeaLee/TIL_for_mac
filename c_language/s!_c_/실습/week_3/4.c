#include <stdio.h>


int main(){
    int year[4], month[4], day[4];
    FILE *fp = fopen("day.txt", "r");

    for(int i = 0; i < 4; i++){

        fscanf(fp, "%d³â %d¿ù %dÀÏ", &year[i], &month[i], &day[i]);
    }

    for(int i = 0; i < 4; i++){
        printf("%d %d %d\n", year[i], month[i], day[i]);
    }

    fclose(fp);

    return 0;
}