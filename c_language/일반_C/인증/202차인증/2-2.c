#include <stdio.h>

int main(){
    int x[100], y[100], k[100], num, m, i, count = 0, result = 0, ycount = 0, j, check, kcount = 0;
    while(1){
        scanf("%d", &num);
        if(num < 0){
            break;
        }
        x[count] = num;
        count++;
    }
    scanf("%d", &m);
    for(i = 0; i < count; i++){
        result += x[i];
        k[kcount] = x[i];
        kcount++;
        if(result >= m){
            check = 1;
            for(j = 0; j < ycount; j++){
                if(y[j] == result){
                    check = 0;
                    result = 0;
                    kcount = 0;
                    break;
                }
            }
            if(check == 1){
                for(j = 0; j < kcount; j++){
                    printf("%d ", k[j]);
                }
                kcount = 0;
                y[ycount] = result;
                ycount++;
                printf("%d\n", result);
                result = 0;

            }
        }
    }
    if(result < m){
        for(i = 0; i < kcount; i++){
            printf("%d ", k[i]);
        }
        printf("%d", result);
    }



    return 0;
}