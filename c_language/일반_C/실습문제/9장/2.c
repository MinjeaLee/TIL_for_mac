#include <stdio.h>

int main(){
    char ch[20] = {'\0', }, tmp;
    char *ptr_ch;
    int count = 0;

    ptr_ch = ch;

    for(int i = 0; i < 20; i++){
        scanf("%c", &tmp);
        if(tmp == '\n'){
            break;
        }
        else{
            *(ptr_ch + i) = tmp;
        }
    }
    
    for(int i = 20; i >= 0; i--){
        if(*(ptr_ch + i) == '#'){
            count++;
        }
    }

    for(int i = 20; i >= 0; i--){
        if(*(ptr_ch + i) == '#'){
            count--;
        }
        if(count == 0){
            if(*(ptr_ch + i) != '#'){
                printf("%c", *(ptr_ch + i));
            }
        }
    }
    

    return 0;
}