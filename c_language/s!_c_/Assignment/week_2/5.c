#include <stdio.h>
#include <string.h>

void eliminate(char *str){
    for (; *str != '\0'; str++){
        if (*str == '"'){
            strcpy(str, str + 1);
            str--;
        }
    }
}

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


int main(){
    char names[200] = {0,}, array[50][20] = {0,},*p_names, *p_tmp;
    int check = 0, people = 0, index;
    int min;
    char tmp[20];

    gets(names);

    for(p_tmp = names; p_tmp < names + strlen(names); p_tmp++){
        if(*p_tmp == '"' && check == 0){
            for(;;p_tmp++){
                if(*p_tmp == ' '){
                    *p_tmp = '_';
                    check = 1;
                    p_tmp++;
                    break;
                }
            }
        }
        if(*p_tmp == '"' && check == 1){
            check = 0;
        }
    }

    p_names = strtok_2(names , " ");


    for(int i = 0; p_names != NULL; i++){
        for(int j = 0; j < strlen(p_names); j++){
            array[i][j] = p_names[j];
            index++;
        }
        p_names = strtok_2(NULL, " ");
        people++;
    }

    for(int i = 0; i < people; i++){
        eliminate(array[i]);
    }

    for(int i = 0; i < people; i++){
        p_tmp = strchr(array[i], '_');
        if(p_tmp){
            *p_tmp = ' ';
        }
    }

    for( int i = 0; i < people - 1; i++){
        min = i;
        for(int k = i + 1; k < people; k++){
            if(strcmp(array[min], array[k]) > 0){
                min = k;
            }
        }
        strcpy(tmp, array[i]);
        strcpy(array[i], array[min]);
        strcpy(array[min], tmp);
    }

    for(int i = 0; i < people; i++){
        printf("%s\n", array[i]);
    }
    
    return 0;
}