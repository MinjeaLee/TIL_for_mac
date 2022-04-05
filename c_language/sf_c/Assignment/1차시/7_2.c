#include <stdio.h>
#include <string.h>

char* strrev_1(char* str){
    int startIdx, endIdx;
    if(!str || !*str)    return (char *)-1;
    startIdx = 0;
    endIdx = strlen(str)-1;
    while(startIdx<endIdx) {
        char tmp = str[startIdx];
        str[startIdx] = str[endIdx];
        str[endIdx] = tmp;
        startIdx ++;
        endIdx --;
    }
    return str;
} 

int main(){
    int n, sum, over_check = 0, num_x, num_y;
    char x[690000], y[690000];
    char result[690000];

    scanf("%d", &n);
    getchar();
    for(int i = 0; i< n; i++){
        scanf("%c", &x[i]);
    }
    getchar();
    for(int i = 0; i< n; i++){
        scanf("%c", &y[i]);
    }

    for(int i = n - 1; i >= 0; i--){
        num_x = x[i] - '0';
        num_y = y[i] - '0';
        if(over_check == 1){
            sum = num_x + num_y + 1;
            if(sum >= 10){
                over_check = 1;
            }
            else{
                over_check = 0;
            }
        }
        else{
            sum = num_x + num_y;
            if(sum >= 10){
                over_check = 1;
            }
            else{
                over_check = 0;
            }
        }
        if(i != 0){
            result[n - i - 1] = '0' + (sum % 10);
        }
        else{
            result[n - i - 1] = '0' + (sum % 10);
            result[n - i] = '1';
        }
    }
    if(over_check == 0){
        result[n] = '\0';
        strrev_1(result);
        printf("%s", result);
    }
    else{
        result[n + 1] = '\n';
        strrev_1(result);
        printf("%s", result);
    }
    

    return 0;
}