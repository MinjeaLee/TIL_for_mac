#include <stdio.h>
//restore github

int main(){
    char x[20];
    int i, uv = 0, unv = 0, sv = 0, snv = 0, word_count = 0, tmp = 0;

    for(i = 0; i < 20; i++){
        scanf("%c", &x[i]);
    }
    for(i = 0; i < 20; i++){
        if('A' <= x[i] && x[i] <= 'Z'){
            if(x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U'){
                uv++;
            }
            else{
                unv++;
            }
        }
        if('a' <= x[i] && x[i] <= 'z'){
            if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u'){
                sv++;
            }
            else{
                snv++;
            }
        }
    }
    for(i = 0; i <= 10; i++){
        tmp = 0;
        if('A' <= x[i] && x[i] <= 'Z'){
            if(x[i] != 'A' || x[i] != 'E' || x[i] != 'I' || x[i] != 'O' || x[i] != 'U'){
               tmp++; 
            }
        }
        if('a' <= x[i +1] && x[i +1] <= 'z'){
            if(x[i +1] == 'a' || x[i +1] == 'e' || x[i +1] == 'i' || x[i +1] == 'o' || x[i +1] == 'u'){
                tmp++;
            }
        }
        if('a' <= x[i +2] && x[i +2] <= 'z'){
            if(x[i +2] != 'a' || x[i +2] != 'e' || x[i +2] != 'i' || x[i +2] != 'o' || x[i +2] != 'u'){
                tmp++;
            }
        }
        
        if(tmp == 3){
            word_count++;
        }
    }
    printf("%d %d %d %d\n%d", unv, snv, uv, sv, word_count);

    return 0;
}