#include <stdio.h>

int main(){
    int x[50], i ,j, num, n[50], count[50], tmp, c = 0, check, ecount;
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        check = 0;
        scanf("%d", &tmp);
        x[i] = tmp;
        for(j = 0; j < i; j++){
            if(x[i] == x[j]){
                check = 1;
                break;
            }
        }
        if(check != 1){
            n[c] = tmp;
            c++;
        }
    }
    for(i = 0; i < c; i++){
        ecount = 0;
        for(j = 0; j < num; j++){
            if(n[i] == x[j]){
                ecount++;
            }
        }
        count[i] = ecount;
    }

    for(i = 0; i < c; i++){
        printf("%d %d\n", n[i], count[i]);
    }
     

    return 0;
}