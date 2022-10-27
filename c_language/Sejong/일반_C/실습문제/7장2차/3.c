#include <stdio.h> 

int main(){
    char table[6][5] = {
        {'Z','E','R','O','-'},
        {'O','N','E','-','-'},
        {'T','W','O','-','-'},
        {'T','H','R','E','E'},
        {'F','O','U','R','-'},
        {'F','I','V','E','-'},
    };
    int n, k = 0;
    while (k < 3)
    {
        k++;
        scanf("%d", &n);
        for(int i = 0; i  < 5; i++){
            printf("%c", table[n][i]);
        }
        printf("\n");
    }
    


    return 0;
}