#include <stdio.h>

int main(){
    char ch[20], tmp;
    int len = 0, count = 0 ;

    for(int i = 0; i < 20; i++){
        scanf("%c", &tmp);
        if(tmp == '\n'){
            break;
        }
        else{
            *(ch + i) = tmp;
            len++;
        }
    }

    for(int i = 0; i < len; i++){
        if(*(ch + i) == '#'){
            break;
        }
        else{
            count++;
        }
    }

    for(int i = count - 1; i >= 0; i--){
        printf("%c", *(ch + i));
    }


    return 0;
}