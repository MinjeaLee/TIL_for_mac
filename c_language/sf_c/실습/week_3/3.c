#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable: 4996)
int main(void) {
    FILE *fp=fopen("test.txt", "w");

    fprintf(fp, "%s\n", "testtest");

    fclose(fp);
}