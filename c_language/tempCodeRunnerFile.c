#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCONTACT 100;

typedef struct _contact{
    char name[21];
    char phone[16];
    char birth[9];
}contact;

int register_contact(contact list[], int person_num){
    contact tmp;

    printf("Name:");
    scanf("%s", list[person_num].name);
    printf("Phone_number:");
    scanf("%s", list[person_num].phone);
    printf("Birth:");
    scanf("%s", list[person_num].birth);

    for(int i = 0; i < person_num - 1; i++){
        for(int j = 0; j < person_num - 1 - i; j++){
            if(strcmp(list[j].name, list[j + 1].name) > 0){
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }

    person_num++;
    return person_num;
}

int Del(contact list[], int person_num, char *name){
    int del_index;
    int check = 0;
    for(int i = 0; i < person_num; i++){
        if(strcmp(list[i].name, name) == 0){
            del_index = i;
            check = 1;
            break;
        }
    }
    if(check == 0){
        printf("NO MEMBER\n");
        return person_num;
    }

    for(int i = person_num; i > del_index; i--){
        list[i - 1] = list[i];
    }
    person_num--;

    return person_num; 
}

int main(){
    contact list[100];
    int menu_num;
    int person_num = 0;
    char del_name[21];
    char search_month[3];

    while(1){
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &menu_num);
        if(menu_num == 1){
            if(person_num >= 100){
                printf("OVERFLOW\n");
            }
            else{
                person_num = register_contact(list, person_num);
                printf("<<%d>>\n", person_num);
            }
        }
        else if(menu_num == 2){
            for(int i = 0; i < person_num; i++){
                printf("%s %s %s\n", list[i].name, list[i].phone, list[i].birth);
            }
        }
        else if(menu_num == 3){
            if(person_num == 0){
                printf("NO MEMBER\n");
                continue;
            }
            printf("NAME:");
            scanf("%s", del_name);
            printf("\n");
            person_num = Del(list, person_num, del_name);
        }
        else if(menu_num == 4){
            printf("Birth:");
            scanf("%s", search_month);
            if(strlen(search_month) == 1){
                for(int i = 0; i < person_num; i++){
                    if(strncmp(search_month, list[i].birth + 5, 1) == 0){
                        printf("%s %s %s\n", list[i].name, list[i].phone, list[i].birth);
                    }
                }
            }
            else if(strlen(search_month) == 2){
                for(int i = 0; i < person_num; i++){
                    if(strncmp(search_month, list[i].birth + 4, 2) == 0){
                        printf("%s %s %s\n", list[i].name, list[i].phone, list[i].birth);
                    }
                }
            }
        }
        else{
            break;
        }
    }

    return 0;
}