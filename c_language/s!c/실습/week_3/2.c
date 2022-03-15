#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    
    scanf("%d", &n);

    char *word = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", word);

    for(int i = n - 1; i >= 0; i--){
        printf("%c", word[i]);
    }
    
    free(word);

    return 0;
}