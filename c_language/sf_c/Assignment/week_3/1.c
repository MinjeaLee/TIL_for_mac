#include <stdio.h>
#include <string.h>

typedef struct WRORD{
    char word[21];
    int num;

} word;

// function of string to array of word

int main(){
    word list[10];
    char str[201], *p_str;
    int index_1d = 0, index_2d = 0;

    gets(str);

    for(p_str = str; *p_str != '\0'; p_str++){
        if(('a' <= *p_str && *p_str<='z') || ('A' <= *p_str && *p_str<='Z')){
            list[index_1d].word[index_2d] = *p_str;
            index_2d++;
        }
        else{
            list[index_1d].word[index_2d] = '\0';
            list[index_1d].num = 1;
            index_1d++;
            index_2d = 0;
        }
    }
    
    if(('a' <= str[strlen(str) - 1] && str[strlen(str) - 1]<='z') || ('A' <= str[strlen(str) - 1] && str[strlen(str) - 1]<='Z')){
        list[index_1d].num = 1;
        index_1d++;
    }

    for(int i = 0; i < index_1d - 1; i++){
        for(int j = i + 1; j < index_1d; j++){
            if(strcmp(list[i].word, list[j].word) == 0){
                list[i].num++;
                strcpy(list[j].word, ".");
            }
        }
    }

    for(int i = 0; i < index_1d; i++){
        if(strcmp(list[i].word, ".") == 0) {
            continue;
        }
        else{
            printf("%s %d\n", list[i].word, list[i].num);
        }
    }

    return 0;
}