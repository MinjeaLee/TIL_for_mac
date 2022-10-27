#include <stdio.h>
#include <string.h>

int check(char *str){
    int len = strlen(str);
    int result = 1;

    for(int i = 0; i < len / 2; i++){
        if(*(str + i) != *(str + len - i - 1)){
            result = 0;
            break;
        }
    }

    if(result == 1){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    char x[31];

    scanf("%s", &x);

    printf("%d ", strlen(x));

    printf("%d", check(x));


    return 0;
}