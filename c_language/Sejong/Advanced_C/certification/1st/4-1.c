#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stock{
    char sid[7];
    int qty;
    double cost;
    double total;
    double avg;
}stock;

int main(){
    stock list[100];
    int n, same_count, same_count_qty;
    double sum_cost, avg, same_total, total;
    char check_id[7];

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%s %d %lf", &list[i].sid, &list[i].qty, &list[i].cost);
        getchar();
    }

    for(int i = 0; i < n; i++){
        strcpy(check_id, list[i].sid);
        sum_cost = 0;
        same_count = 0;
        same_count_qty = 0;
        same_total = 0;
        for(int j = 0; j < n; j++){
            if(strcmp(list[j].sid, check_id) == 0){
                same_count++;
                sum_cost += list[j].cost;
                same_count_qty += list[j].qty;
                total = list[j].qty * list[j].cost;
                same_total += total;
            }
        }
        list[i].avg = same_total / same_count_qty;
        list[i].qty = same_count_qty;
        list[i].total = same_total;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(list[j].sid, list[i].sid) == 0){
                strcpy(list[j].sid, "P");
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(strcmp(list[i].sid, "P") == 0){
            continue;
        }
        else{
            printf("%s %d %.2lf %.2lf\n", list[i].sid, list[i].qty, list[i].avg, list[i].total);
        }
        
    }

    return 0;
}