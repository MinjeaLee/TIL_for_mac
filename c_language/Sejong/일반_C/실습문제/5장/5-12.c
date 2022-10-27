// if문으로 풀기
// #include <stdio.h>

// int main(){
//     int menu, money;
//     int count_5 = 0, count_1 = 0;
//     scanf("%d", &menu);
//     scanf("%d", &money);
//     if (menu == 1){
//         printf("Americano\n");
//         money -= 500;
//     }
//     else if (menu == 2){
//         printf("Cafe Latte\n");
//         money -= 400;
//     }
//     else{
//         printf("Lemon Tea\n");
//         money -= 300;
//     }
//     if (money >= 500){
//         count_5 = (money / 500);
//         money -= (500 * count_5);
//     }
//     if (money >= 100){
//         count_1 = (money / 100);
//         money -= (100 * count_1);
//     }

//     printf("%d %d", count_5, count_1);
//     return 0;
// }


#include <stdio.h>

int main(){
    int menu, money;
    int count_5 = 0, count_1 = 0;
    scanf("%d", &menu);
    scanf("%d", &money);

    switch(menu){
        case 1:
        printf("Americano\n");
        money -= 500;
        break;

        case 2:
        printf("Cafe Latte\n");
        money -= 400;
        break;

        case 3:
        printf("Lemon Tea\n");     
        money -= 300;
        break;
    }
    count_5 = (money / 500);
    count_1 = (money % 500 / 100);
    
    printf("%d %d", count_5, count_1);


    return 0;
}