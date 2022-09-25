#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void upHeap(int i)
{
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

void downHeap(int i){
    int bigger, temp;
    if ((n < (i * 2)) && (n < (i * 2 + 1))){
        return;
    }
    bigger = i * 2;
    if (n >= i * 2 + 1){
        if (H[i * 2 + 1] > H[bigger]){
            bigger = i * 2 + 1;
        }
    }
    if (H[i] >= H[bigger]){
        return;
    }
    temp = H[i];
    H[i] = H[bigger];
    H[bigger] = temp;
    downHeap(bigger);
}

int removeMax(){
    int key;
    key = H[1];
    H[1] = H[n--];
    downHeap(1);

    return key;
}

void printHeap(){
    for (int i = 1; i < n + 1; i++){
        printf(" %d", H[i]);
    }
    printf("\n");
}

void main(){
    char p;
    int key;

    while (1){
        scanf("%c", &p);
        if (p == 'i'){
            scanf("%d", &key);
            insertItem(key);
            printf("0\n");
            getchar();
        }
        else if (p == 'd'){
            printf("%d\n", removeMax());
            getchar();
        }
        else if (p == 'p'){
            printHeap();
            getchar();
        }
        else if (p == 'q'){
            break;
        }
    }
}