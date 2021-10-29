#include <stdio.h>
#include <string.h>

char *word_to_arry(char *str){
    
}


int main(){
    char str[101], *p_i, *p_j;
    char word[50][50], *p;
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

    printf("%s", word[n - 1]);

    return 0;
}