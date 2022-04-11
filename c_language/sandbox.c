// Create a program that receives the amount of integer n repeatedly until the termination condition, outputs the maximum number of times the odd number is continuous, and outputs the maximum num of that interval.
// Exit Condition: 0 Input
// If the maximum number of times is the same, the maximum value of the first time is output.
// Output 'None' if odd number is not input
// Prohibition of arrays

// Input examples 1
// 5 6 11 13 17 19 20 3 8 4 0
// Example of output 1
// 4 19

// Input Example 2
// 26 50 34 0
// Output example 2
// None

// Input Example 3
// 19 51 49 53 2 100 30 5 27 63 7 2 0
// Output Example 3
// 4 53
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, max = 0, max_count = 0, count = 0;
    int tmp_max = 0, flag = 0;

    scanf("%d", &n);

    while(1){

        if(n % 2 == 1){
            count++;
            if(tmp_max < n){
                tmp_max = n;
            }
            if(count >= max_count){
                flag = 1;
                max_count = count;
            }
        }
        else{
            count = 0;
            flag = 0;
        }

        if(flag == 1 && max < tmp_max){
            max = tmp_max;
        }

        scanf("%d", &n);
        if(n == 0){
            break;
        }

    }

    if(max_count == 0){
        printf("none");
    }
    else{
        printf("%d %d", max_count, max);
    }
              
    return 0;
}