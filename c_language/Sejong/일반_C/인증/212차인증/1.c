#include <stdio.h>

int main(){
    char input;
    int k, l, x[10] = {0, }, i;
    while(1){
        scanf("%c %d %d", &input, &k, &l);
        getchar();
        if(input == 'n'){
            break;
        }
        if(k > 10 || l > 4){
            printf("please input correctly\n");
        }
        else if(x[k -1] != 0){
            printf("please select another room\n");
        }
        else{
            x[k - 1] = l;
            for(i = 0; i < 10; i++){
                printf("%d ", x[i]);
            }
            printf("\n");
        }

    }
    

    return 0;
}