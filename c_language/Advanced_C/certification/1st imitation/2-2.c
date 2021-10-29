#include <stdio.h>
#include <string.h>

char *word_to_arry(char *str){
    
}


int main(){
    char str[101], *p_i, *p_j;
    char word[50][50], *p, tmp[51];
    int word_index_1d = 0, word_index_2d = 0;
    int n;

    gets(str);

    scanf("%d",&n);


    for(p = str; *p != '\0'; p++){  
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
    
    if('a' <=str[strlen(str) - 1]<= 'z'){
        word_index_1d++;
    }    

    printf("%s\n", word[n - 1]);

    for(int i = 0; i < word_index_1d - 1; i++){
        for(int j = 0; j < word_index_1d; j++){
            if(strcmp(word[i], word[j]) > 0){
                strcpy(tmp, word[i]);
                strcpy(word[i], word[j]);
                strcmp(word[j], tmp);
            }
        }
    }
    printf("%s", word[0]);

    return 0;
}