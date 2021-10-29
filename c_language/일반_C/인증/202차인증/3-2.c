#include <stdio.h>

int main(){
    int x[100], grade[20], n, i, j, tmp, a_c, b_c;
    int gcount = 0;
    scanf("%d", &n);
    a_c = n * 0.3;
    b_c = n * 0.7;
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(x[i] < x[j]){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++){
        printf(" %d", x[i]);
    }
    printf("\n");
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(x[i] == x[j]){
                x[j] = -1;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(x[i] == -1){
            for(j = i - 1; j > 0; j--){
                if(x[j] != -1){
                    printf(" %d", j + 1);
                    grade[gcount] = j + 1;
                    gcount++;
                    break;
                }
            }
        }
        else{
            printf(" %d" , i + 1);
            grade[gcount] = i + 1;
            gcount++;
        }
    }
    printf("\n");
    for(i = 0; i < n; i++){
        if(grade[i] <= a_c){
            printf(" A");
        }
        else if(grade[i] <= b_c){
            printf(" B");
        }
        else{
            printf(" C");
        }
    }
    

    return 0;
}