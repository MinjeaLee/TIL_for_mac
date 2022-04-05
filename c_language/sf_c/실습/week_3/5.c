#include <stdio.h>

int main(){
    char name[20], num[20], weight[20];
    int count;

    FILE *fp = fopen("src.txt", "r");
    FILE *fp_2 = fopen("dse.txt", "w");

    fscanf(fp, "%s\n%s\n%s", name, num, weight);
    fprintf(fp_2, "%s\n%s\n%s", name, num, weight);

    fclose(fp);
    fclose(fp_2);

    return 0;
}