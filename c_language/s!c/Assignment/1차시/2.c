#include <stdio.h>

int isThird(int arr[], int val, int n);
int countThree(int val);
void calc(int arr[], int min, int max, int n);

int isThird(int arr[], int val, int n){
    int over_count = 0;

    for(int i = 0; i < n; i++){
        if(val < arr[i]){
            over_count++;
        }
    }
    if(over_count == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int countThree(int val){
    int count_three = 0, check_num;
   
    while(val != 0){
        check_num = val % 10;
        if(check_num == 3){
            count_three++;
        }
        val /= 10;
    }

    return count_three;
}

void calc(int arr[], int min, int max, int n){
    int available[300], avail_count = 0;
    int max_three_num, max_three_count = -1;

    for(int i = min; i <= max; i++){
        if(isThird(arr, i, n)){
            available[avail_count] = i;
            avail_count++;
        }
    }
    if(avail_count == 0){
        printf("shitte, no jam\n");
    }
    else{
        for(int i = 0; i < avail_count; i++){
            if(max_three_count < countThree(available[i])){
                max_three_count = countThree(available[i]);
                max_three_num = available[i];
            }
        }
        if(max_three_count == 0){
            if(avail_count < 3){
                if(avail_count == 2){
                    if(available[0] > available[1]){
                        printf("Shitte, %d\n", available[0]);
                    }
                    else{
                        printf("Shitte, %d\n", available[1]);
                    }
                }
                else{
                    printf("Shitte, %d\n", available[0]);
                }
            
            }
            else{
                printf("Gabbi, %d\n", available[avail_count - 3]);
            }
        }
        else{
            printf("Yope, %d\n", max_three_num);
        }
        // if(avail_count < 3){
        //     if(available[0] > available[1]){ 
        //         printf("Shitte, %d\n", available[0]);
        //     }
        //     else{
        //         printf("Shitte, %d\n", available[1]);
        //     }
        // }
        // else{
            // for(int i = 0; i < avail_count; i++){
            //     if(max_three_count < countThree(available[i])){
            //         max_three_count = countThree(available[i]);
            //         max_three_num = available[i];
            //     }
            // }
            // if(max_three_count == 0){
            //     printf("Gabbi, %d\n", available[avail_count - 3]);
            // }
            // else{
            //     printf("Yope, %d\n", max_three_num);
            // }
        // }
    }

}


int main(){
    int n, min, max, arr[300];

    scanf("%d %d %d", &n, &min, &max);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    calc(arr, min, max, n);

    return 0;
}