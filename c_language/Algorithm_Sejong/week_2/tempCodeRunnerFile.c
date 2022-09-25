#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int HEAP[100];
int N = 0;

void upHeap(int index){
    // Move upward to the position that is stored in the hip position I
    int temp;

    if (i == 1){
        return;
    }

    if (HEAP[i] <= HEAP[i / 2]){
        return;
    }

    temp = HEAP[i];
    HEAP[i] = HEAP[i / 2];
    HEAP[i / 2] = temp;
    upHeap(i / 2);
}

void downHeap(int index){
    // Go down to the position that is stored in the hip position index
    int temp;  
    int max = index;

    if (index * 2 <= N && HEAP[index * 2] > HEAP[max]){
        max = index * 2;
    }

    if (index * 2 + 1 <= N && HEAP[index * 2 + 1] > HEAP[max]){
        max = index * 2 + 1;
    }

    if (max == index){
        return;
    }

    temp = HEAP[index];
    HEAP[index] = HEAP[max];
    HEAP[max] = temp;
    downHeap(max);
}

void insertHeap(int key){
    // Insert the key into the heap
    N = N + 1;
    HEAP[N] = key;
    upHeap(N);
}

int removeMax(){
    // renew the N (total number of keys) after the downheap call
    // Deleted key return
    int temp = HEAP[1];
    HEAP[1] = HEAP[N];
    N = N - 1;
    downHeap(1);
    return temp;
}

void print_Heap(){
    // print the keys stored in the heap in level order
    int i;
    for (i = 1; i <= N; i++){
        printf(" %d", HEAP[i]);
    }
    printf("\n");
}

void main(){
   char p;
   int key;

   while (1) {
      scanf("%c", &p);
      if (p == 'i') {
         scanf("%d", &key);
         insertItem(key);
         printf("0\n");
         getchar();
      }
      else if (p == 'd') {
         printf("%d\n", removeMax());
         getchar();
      }
      else if(p == 'p') {
        print_Heap();
         getchar();
      }
      else if (p == 'q') {
         break;
      }
   }
}