#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// quick sort

int find_pivot(int list[], int left, int right)
{
    int mid = (left + right) / 2;
    if (list[left] > list[mid])
    {
        if (list[mid] > list[right])
        {
            return mid;
        }
        else if (list[left] > list[right])
        {
            return right;
        }
        else
        {
            return left;
        }
    }
    else
    {
        if (list[left] > list[right])
        {
            return left;
        }
        else if (list[mid] > list[right])
        {
            return right;
        }
        else
        {
            return mid;
        }
    }
}

int inplacepartition(int list[], int left, int right) 
// use find_pivot function
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;

    pivot = find_pivot(list, left, right);

    temp = list[left];
    list[left] = list[pivot];
    list[pivot] = temp;
    
    do
    {
        do
        {
            low++;
        } while (low <= right && list[low] < list[left]);
        do
        {
            high--;
        } while (high >= left && list[high] > list[left]);
        if (low < high)
        {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    } while (low < high);
    temp = list[left];
    list[left] = list[high];
    list[high] = temp;
    return high;
}

void inPlaceQuickSort(int list[], int left, int right)
{
    if (left < right)
    {
        int q = inplacepartition(list, left, right);
        inPlaceQuickSort(list, left, q - 1);
        inPlaceQuickSort(list, q + 1, right);
    }
}

int main(){
    int *arr;
    int n;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    inPlaceQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}