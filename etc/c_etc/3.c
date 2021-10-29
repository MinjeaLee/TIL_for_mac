#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void sort(int arr[], int n){
    int *i, *j;
    int tmp;

    for(i = arr; i < arr + n - 1; i++){
        for(j = i + 1; j < arr + n; j++){
            if(*i < *j){
                tmp = *i;
                *i = *j;
                *j = tmp; 
            }
        }
    }
}

int main(){
    int x[10], y[10];
    int n = 0, m = 0, tmp;
    int *p_i, *p_j;
    int merge_i = 0, merge_j = 0;

    for(p_i = x;;p_i++){
        scanf("%d",&tmp);
        if(tmp == 0){
            break;
        }
        *p_i = tmp;
        n++;
    }
    for(p_i = y;;p_i++) {
        scanf("%d", &tmp);
        if(tmp == 0){
            break;
        }
        *p_i = tmp;
        m++;
    }

    sort(x, n);
    sort(y, m);
    

    



    

    return 0;
}