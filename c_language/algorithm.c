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

// Ư�� ���� ����
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

// ���� ����
void bubble_sort(int list[], int n){

  int i, j, temp;

  for(i=n-1; i>0; i--){
    // 0 ~ (i-1)���� �ݺ�
    for(j=0; j<i; j++){
      // j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
      if(list[j]<list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
}

// ���ڿ� -> �ܾ� �߶� ���߹迭�� �ֱ�
char *word_to_arry(char *str){
    char word[50][50], string[101], *p;
    int word_index_1d = 0, word_index_2d = 0;

    for(p = string; p < str + strlen(str); p++){  
        if(*p != ' ' && *p != '.'){             // �ܾ� ���� ���� ����
            word[word_index_1d][word_index_2d] = *p;
            word_index_2d++;
        }
        else{
            word[word_index_1d][word_index_2d] = '\0';
            word_index_1d++;
            word_index_2d = 0;
        }
    }   
    if(){ // ���� ������ ���ڰ� ���ĺ��̸� 
        word_index_1d++; // ++ 
    }    
    return word;
}


// ���ڿ� ���� �Լ�
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


// realloc
void size_up_malloc(int *s, int **arr, char *str){
    int newsize = *s + strlen(str); // strlen(str) 부분 -> 늘리고 싶은 크기
    int *temp;
    temp = malloc(sizeof(int) * newsize);


    for (int i = 0; i < *s; i++){
        temp[i] = (*arr)[i];
    }

    free(*arr);  
    *arr = temp; 
    *s = newsize;
}
