#include <stdio.h>
#include <string.h>

void swap(int *x, int *y){
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    char region[21];
    char name_2[21];
    char old[21];
    char p_tmp_str[21];
    char name[10000][21];
    char id_st[9];
    char id [10000][9];

    int num;
    // int id_st;
    // int id[10000];

    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        scanf("%s %s %s %s", region, name_2, old, id_st);

        strcpy(name[i], name_2);
        strcpy(id[i], id_st);

        // id[i] = id_st;
    }    

    for(int s = 0; s < num - 1; s++){
        for(int i = 0; i < num - 1 - s; i++){
            if(strcmp(name[i], name[i + 1]) > 0){
                strcpy(p_tmp_str, name[i]);
                strcpy(name[i], name[i + 1]);
                strcpy(name[i + 1], p_tmp_str);
                // swap(id + i, id + i + 1);
                strcpy(p_tmp_str, id[i]);
                strcpy(id[i], id[i + 1]);
                strcpy(id[i + 1], p_tmp_str);

            }
        }
    }           // sort std -> string

    for(int i = 0; i < num - 1; i++){
        for(int j = i + 1; j < num; j++){
            if(strcmp(name[i], name[j]) == 0){
                if(strcmp(id[i], id[j]) > 0){
                    strcpy(p_tmp_str, id[i]);
                    strcpy(id[i], id[i + 1]);
                    strcpy(id[i + 1], p_tmp_str);
                    strcpy(p_tmp_str, name[i]);
                    strcpy(name[i], name[i + 1]);
                    strcpy(name[i + 1], p_tmp_str);
                }
            }
        }
    }        // sort std -> id
    
    for(int i = 0; i < num; i++){
        printf("%s %s\n", name[i], id[i]);
    }

    return 0;
}