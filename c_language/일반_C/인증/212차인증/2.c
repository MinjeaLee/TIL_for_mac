#include <stdio.h>

int main(){
    char x[100], ch;
    int count = 0, tmp, i, word_count = 0;
    while(1){
        scanf("%c", &ch);
        if(ch == '*'){
            break;
        }
        if('a' <= ch && ch <= 'z'){
            ch = ch - 'a';
            ch = 'A' + ch;
            x[count] = ch;
            count++;
        }
        else if('A' <= ch && ch <= 'Z'){
            ch = ch - 'A';
            ch = 'a' + ch;
            x[count] = ch;
            count++;
        }
    }
    for(i = 0; i < count; i++){
        printf("%c", x[i]);
    }
    printf("\n");
    for(i = 0; i <= count - 2; i++){
        tmp = 0;
        if('A' <= x[i] && x[i] <= 'Z'){
            if(x[i] != 'A' && x[i] != 'E' && x[i] != 'I' && x[i] != 'O' && x[i] != 'U'){
                tmp++; 
            }
        }
        if('a' <= x[i +1] && x[i +1] <= 'z'){
            if(x[i +1] == 'a' || x[i +1] == 'e' || x[i +1] == 'i' || x[i +1] == 'o' || x[i +1] == 'u'){
                tmp++;
            }
        }
        if('a' <= x[i +2] && x[i +2] <= 'z'){
            if(x[i +2] != 'a' && x[i +2] != 'e' && x[i +2] != 'i' && x[i + 2] != 'o' && x[i +2] != 'u'){
                tmp++;
            }
        }
        if(tmp == 3){
            word_count++;
        }
    }
    printf("%d", word_count);
    

    return 0;
}