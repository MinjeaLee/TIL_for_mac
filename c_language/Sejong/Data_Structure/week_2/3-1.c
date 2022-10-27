#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prefix average

//func of O(n^2)
int *prefixAverage_1(int *table, int n){
    int *result_table;
    int sum;

    result_table = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j <= i; j++){
            sum += table[j];
        }
        result_table[i] = (int)(sum / (double)(i + 1) + 0.5);
    }


    return result_table;
}

int *prefixAverage_2(int *table, int n){
    int *result_table;
    int sum = 0;

    result_table = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        sum += table[i];
        result_table[i] = (int)(sum / (double)(i + 1) + 0.5);
    }

    return result_table;
}


int main(){
    int *table;
    int *result_1, *result_2;
    int n;

    scanf("%d", &n);

    table = (int *)malloc(sizeof(int) * n);


    for(int i = 0; i < n; i++){
        scanf("%d", &table[i]);
    }

    result_1 = prefixAverage_1(table, n);
    result_2 = prefixAverage_2(table, n);

    for(int i = 0; i < n; i++){
        printf("%d ", result_1[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", result_2[i]);
    }

    // free(table);
    // free(prefixAverage_1);
    // free(prefixAverage_2);
    

    return 0;
}