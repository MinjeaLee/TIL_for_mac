#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// strrev

char* strrev_1(char* str){
    int start, end;
    char tmp;
    if(!str || !*str)    return (char *) -1;
    start = 0;
    end = strlen(str)-1;
    while(start<end) {
        tmp = str[start];
        str[start] = str[end];
    
    
        str[end] = tmp;
        start ++;
        end --;
    }
    return str;    
} 

// 특정 문자 제거
void Eliminate(char *str, char ch)
{
    for (; *str != '\0'; str++)
    {
        if (*str == ch)
        {
            strcpy(str, str + 1);
            str--;
        }
    }
}


// strtok
char* strtok_2(char *str, char *std){
    char* start_str = 0;
    static char *tstr;
    int i;
    if(str != NULL){
        start_str = str;
    }
    else{
        start_str = tstr;
    }
    if(strlen(start_str) < 1){
        return NULL;
    }
    for(i = 0; i < strlen(start_str); i++){
        if(start_str[i] == (*std) || start_str[i] == '\0'){
            start_str[i] = '\0';
            break;
        }
    }
    tstr = &start_str[i + 1];
    return start_str;
}

// 버블 정렬
void bubble_sort(int list[], int n){

  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)까지 반복
    for(j=0; j<i; j++){
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}

// 문자열 -> 단어 잘라 이중배열에 넣기
char *word_to_arry(char *str){
    char word[50][50], string[101], *p;
    int word_index_1d = 0, word_index_2d = 0;

    for(p = string; p < str + strlen(str); p++){  
        if(*p != ' ' && *p != '.'){             // 단어 끊을 조건 삽입
            word[word_index_1d][word_index_2d] = *p;
            word_index_2d++;
        }
        else{
            word[word_index_1d][word_index_2d] = '\0';
            word_index_1d++;
            word_index_2d = 0;
        }
    }   
    if(){ // 만약 마지막 글자가 알파벳이면 
        word_index_1d++; // ++ 
    }    
    return word;
}


// 문자열 삽입 함수
void StringAdd(char arr[], char ch, int index) {
    char* p;
    int len;

    len = strlen(arr);

    for (p = arr + len; p > arr + index; p--){
        *p = *(p - 1);
    }
    *(arr + index) = ch;

    *(arr + strlen(arr)) = '\0';
}
