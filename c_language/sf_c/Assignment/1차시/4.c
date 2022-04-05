#include <stdio.h>

int main(){
    int case_num, n, old[1000];
    int total_old, count_under_aver;
    double aver_old, result;

    scanf("%d", &case_num);
    for(int i = 0; i < case_num; i++){
        scanf("%d", &n);
        if(n != 0){
            total_old = 0;
            for(int j = 0; j < n; j++){
                scanf("%d", &old[j]);
                total_old += old[j];
            }
            aver_old = (double)total_old / (double)n;
            count_under_aver = 0;
            for(int j = 0; j < n; j++){
                if(old[j] < aver_old){
                    count_under_aver++;
                }
            }
            result = ((double)count_under_aver / (double)n) * 100;
            printf("%.3lf%%\n", result);
        }
    }

    return 0;
}