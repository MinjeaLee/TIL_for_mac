#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int HEAP[100];
int N = 0;

void upHeap(int i){
    // Move upward to the position that is stored in the hip position I
    int temp;
    // int i;

    if (i == 1){    // 루트 노드인 경우 종료
        return;
    }
    if (HEAP[i] <= HEAP[i / 2]){    // 부모 노드보다 작거나 같은 경우 종료
        return;
    }
    // 부모 노드보다 큰 경우 부모와 자리 바꾸기
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
        // 왼쪽 자식 노드가 N보다 작으면서, 왼쪽 자식 노드가 max보다 큰 경우
        max = index * 2;
    }

    if (index * 2 + 1 <= N && HEAP[index * 2 + 1] > HEAP[max]){
        // 오른쪽 자식 노드가 N보다 작으면서, 오른쪽 자식 노드가 max보다 큰 경우
        max = index * 2 + 1;
    }

    if (max == index){
        // max가 index와 같으면 자신이 가장 큰 노드이므로 종료
        return;
    }

    temp = HEAP[index];
    HEAP[index] = HEAP[max];
    HEAP[max] = temp;
    downHeap(max);
}

void insertItem(int key){
    // Insert the key into the heap
    N = N + 1;
    HEAP[N] = key;
    upHeap(N);
}

int removeMax(){
    // renew the N (total number of keys) after the downheap call
    // Deleted key return
    int temp = HEAP[1]; // 루트 노드 임시 저장
    HEAP[1] = HEAP[N];  // 루트 노드를 마지막 노드로
    N = N - 1;  // N의 갯수를 --
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

int main(){
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