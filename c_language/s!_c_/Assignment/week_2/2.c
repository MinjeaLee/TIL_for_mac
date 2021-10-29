#include <stdio.h>
#include <string.h>

int main(){
    char string[10][10], word[10], tmp;
    int len_word, check, total = 0, str_index;

    for(int i = 0; i < 10; i++){
        str_index = 0;
        for(int j = 0; j < 10; j++){
            scanf("%c", &tmp);
            getchar();
            // if(tmp == ' '){
            //     continue;
            // }
            // else{
            //     string[i][str_index] = tmp;

            // }
            string[i][j] = tmp;
        }
    }
    scanf("%s", word);
    // ¿Þ -> ¿À
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 - strlen(word) + 1; j++){
            if(string[i][j] == *word){
                check = 0;
                for(int k = 0; k < strlen(word); k++){
                    if(string[i][j + k] == word[k]){
                        check++;
                    }
                }
                if(check == strlen(word)){
                    total++;
                    j = j + strlen(word) - 1;
                }
            }
        }
    }
    // À§ -> ¾Æ·¡
    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10 - strlen(word) + 1; i++){
            if(string[i][j] == *word){
                check = 0;
                for(int k = 0; k < strlen(word); k++){
                    if(string[i + k][j] == word[k]){
                        check++;
                    }
                }
                if(check == strlen(word)){
                    total++;
                    i = i + strlen(word) - 1;
                }
            }
        }
    }

    // ¿Þ À§ -> ¿À ¾Æ·¡
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(string[i][j] == *word){
                check = 0;
                for(int k = 0; k < strlen(word); k++){
                    if(i + k >= 10 || j + k >= 10){
                        break;
                    }
                    else{
                        if(string[i + k][j + k] == word[k]){
                            check++;
                        }
                    }
                }
                if(check == strlen(word)){
                    total++;
                }
            }
        }
    }
    
    printf("%d", total);

    return 0;
}