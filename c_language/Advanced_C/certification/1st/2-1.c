#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


int main(){
    char str[101] = {0, }, word[50][50] = {0,}, *p;
    int word_index_1d = 0, word_index_2d = 0;
    int max_index;
    char max_str[50] = "zzzzzz";

    gets(str);

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
    if('a' <= str[strlen(str) - 1] && str[strlen(str) - 1] <= 'z'){  
        word_index_1d++;
    } 

    for(int i = 0; i < word_index_1d; i++){
        if(strcmp(word[i], max_str) < 0){
            strcpy(max_str, word[i]);
            max_index = i;
        }
    }


    printf("%s", word[max_index]);


    return 0;
}