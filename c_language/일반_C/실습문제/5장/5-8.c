// ��ø if �� ���
#include <stdio.h>

int main(){
    int year;
    scanf("%d", &year);
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                printf("leap year");
            }
            else{
                printf("common year");
            }
        }
        else{
            printf("leap year");
        }
    }
    else{
        printf("common year");
    }


    return 0;
}


// ���� if else�� ���

// #include <stdio.h>

// int main(){
//     int year;
//     scanf("%d", &year);
//     if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0){
//         printf("leap year");
//     }
//     else if(year % 4 == 0 && year % 100 != 0){
//         printf("leap year");
//     }

//     else{
//         printf("common year");
//     }

//     return 0;
// }