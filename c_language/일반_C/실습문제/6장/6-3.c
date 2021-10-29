#include <stdio.h>

int main(){
    int num, user, i = 0;
    scanf("%d", &num);

    do{
        scanf("%d", &user);
        if (user > num){
            printf("%d>?\n", user);
        }
        else if(user < num){
            printf("%d<?\n", user);
        }
        else{
            printf("%d==?\n", user);
        }
        i++;
        if(user == num){
            break;
        }
    }  while(user != num);

    printf("%d", i);

    return 0;
}