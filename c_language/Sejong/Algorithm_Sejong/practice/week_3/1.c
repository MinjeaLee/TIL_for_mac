#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Heap sort - single key

int H[100];
int n;

void inPlaceHeapSort();
void printArray();
void downHeap(int i);
void insertItem(int key);
void upHeap(int i);
void buildHeap();
void removeMax(int i);

int main(){
    int key, val;
    scanf("%d",&key);
    for(int i = 1; i <= key; i++){
        scanf("%d",&val);
        insertItem(val);

    }
    inPlaceHeapSort();
    n = key;
    printArray();
    
    return 0;
}
void downHeap(int i){
    int check, temp;
    if ((n < (i * 2)) && (n < (i * 2 + 1)))
        return;

    check = i * 2;
    if (n >= i * 2 + 1)
    {
        if (H[i * 2 + 1] > H[check])
        {
            check = i * 2 + 1;
        }
    }

    if (H[i] >= H[check])
        return;

    temp = H[i];
    H[i] = H[check];
    H[check] = temp;

    downHeap(check);
}
void buildHeap(){
    for (int i = n / 2; i >= 1; i--){
        downHeap(i);
    }
}
void inPlaceHeapSort(){
    buildHeap();
    for(int i = n; i >= 2; i--){
        // int temp = H[1];
        // H[1] = H[i];
        // H[i] = temp;
        // n--;
        // downHeap(1);
        removeMax(i);
    }
}
void printArray(){
    for(int i = 1; i <= n; i++){
        printf("%d ",H[i]);
    }
    printf("\n");
}

void upHeap(int i){
    int temp;
    if (i == 1){
        return;
    }

    if (H[i] <= H[i / 2]){
        return;
    }

    temp = H[i];
    H[i] = H[i / 2];
    H[i / 2] = temp;
    upHeap(i / 2);
}
void insertItem(int key){
    H[++n] = key;
    upHeap(n);
}

void removeMax(int i){
    int temp = H[1];
    H[1] = H[i];
    H[i] = temp;
    n--;
    downHeap(1);
}
