#include <stdio.h> 

int main(){
    char a[100], b[100], ch;
    int i, j , a_c = 0, b_c = 0, check = 0, count; 
    while(1){
        scanf("%c", &ch);
        if(ch == '*'){
            break;
        }
        a[a_c] = ch;
        a_c++;
    }
    while(1){
        scanf("%c", &ch);
        if(ch == '*'){
            break;
        }
        b[b_c] = ch;
        b_c++;
    }

    if(a_c >= b_c){
        count = b_c;
    }
    else{
        count = a_c;        
    }

    for(i = 0; i < count; i++){
        if(a[i] == b[i]){
            check = 0;
        }
        else if(a[i] < b[i]){
            check = 1;
            break;
        }
        else if(a[i] > b[i]){
            check = 2;
            break;
        }
    }
    if(check == 0){
        if(a_c > b_c){
            check = 2;
        }
        else{
            check = 1;
        }
    }
    if(check == 1){
        for(i = 0; i < a_c; i++){
            printf("%c", a[i]);
        }
    }
    else if(check == 2){
        for(i = 0; i < b_c; i++){
            printf("%c", b[i]);
        }
    }
    

    return 0;
}