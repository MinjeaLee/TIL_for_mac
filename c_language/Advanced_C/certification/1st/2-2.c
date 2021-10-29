#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


int main(){
    char str[10][101] = {0, }, word_low[50][50] = {0,}, *p, word_high[50][50] = {0, };
    int low_word_index_1d = 0, low_word_index_2d = 0;
    int high_word_index_1d = 0, high_word_index_2d = 0;
    int max_index, n, min_index;
    char max_str[50] = "zzzzzz", min_str[50] = "a";
    int len_min = 1024, len_max = -1, len, len_max_index, len_min_index;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        gets(str[i]);
        len = strlen(str[i]);
        if(len < len_min){
            len_min = len;
            len_min_index = i;
        }
        if(len > len_max){
            len_max = len;
            len_max_index = i;
        }
    }

    for(p = str[len_min_index]; p < str[len_min_index] + strlen(str[len_min_index]); p++){ 
         if(*p != ' '){             
            word_low[low_word_index_1d][low_word_index_2d] = *p;
            low_word_index_2d++;
        }
        else{
            word_low[low_word_index_1d][low_word_index_2d] = '\0';
            low_word_index_1d++;
            low_word_index_2d = 0;
        }
    }
    
    for(p = str[len_max_index]; p < str[len_max_index] + strlen(str[len_max_index]); p++){ 
         if(*p != ' '){             
            word_high[high_word_index_1d][high_word_index_2d] = *p;
            high_word_index_2d++;
        }
        else{
            word_high[high_word_index_1d][high_word_index_2d] = '\0';
            high_word_index_1d++;
            high_word_index_2d = 0;
        }
    }


    for(int i = 0; i < low_word_index_1d + 1; i++) {
        if(strcmp(word_low[i], max_str) < 0){
            strcpy(max_str, word_low[i]);
            max_index = i;
        }
    }
    for(int i = 0; i < high_word_index_1d + 1; i++) {
        if(strcmp(word_high[i], min_str) > 0){
            strcpy(min_str, word_high[i]);
            min_index = i;
        }
    }


    printf("%s\n%s", word_low[max_index], word_high[min_index]);


    return 0;
}