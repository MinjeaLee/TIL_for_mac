#include <stdio.h>

int main(){
    char x[3], y[3] = {'_', '_', '_'},ch;
    int i, count = 0, j;
    for(i = 0; i < 3 ; i++){
        scanf("%c",&x[i]);
    }
    getchar();

    for(i = 0; i < 5; i++){
        if(count == 3){
            break;
        }
        scanf("%c", &ch);
        getchar();
        
        if(ch == x[0]){
            y[0] = ch; 
            count++; 
        }
        if(ch == x[1]){
            y[1] = ch;
            count++;
        }
        if(ch == x[2]){
            y[2] = ch; 
            count++;
        }
        for(j = 0; j < 3; j++){
            printf(" %c", y[j]);
        }
        printf("\n");
    }

    return 0;
}