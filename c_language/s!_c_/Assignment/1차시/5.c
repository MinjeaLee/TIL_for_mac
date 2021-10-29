#include <stdio.h>
#include <limits.h>

int main(){
    int arr[10], min = INT_MAX, max = INT_MIN, total = 0;
    double avr;
    
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
        total += arr[i];
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }

    avr = total / 10;

    printf("Min : %d\nMax : %d\nAverage : %.0lf", min, max, avr);

    return 0;
}