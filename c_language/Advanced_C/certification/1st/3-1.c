#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(){
    char str[101] = {0, }, str_b[11] = {0, }, str_c[11] = {0, }, word[50][50] ={0 ,}, *p;
    int word_index_1d = 0, word_index_2d = 0;
    char str_result[251];

    gets(str);
    gets(str_b);
    gets(str_c);

    for(p = str; p < str + strlen(str); p++){ 
         if(*p != ' '){             
            word[word_index_1d][word_index_2d] = *p;
            word_index_2d++;
        }
        else{
            word[word_index_1d][word_index_2d] = '\0';
            word_index_1d++;
            word_index_2d = 0;
        }
    }
    
    for(int i = 0; i < word_index_1d + 1; i++){
        if(strncmp(word[i], str_b, strlen(str_b)) == 0){
            strncpy(word[i], str_c, strlen(str_c));
        }
    }

    for(int i = 0; i < word_index_1d + 1; i++){
        strcat(str_result, word[i]);
        strcat(str_result," ");
    }

    printf("%s", str_result);




    return 0;
}