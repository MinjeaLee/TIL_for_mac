#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// func section reverse array 
// if array is {1, 2, 3, 4}
// section is (1, 3)
// result is {1, 4, 3, 2}
void reverse_array(int *array, int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[100];
    int n, section_num;
    int start_index, end_index;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &section_num);
    for(int i = 0; i < section_num; i++){
        scanf("%d %d", &start_index, &end_index);
        reverse_array(arr, start_index, end_index);
    }

    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }

    return 0;
}