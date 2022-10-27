#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int H[100], n = 0;

void downHeap(int i)
{
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

void buildHeap()
{
    for (int i = n / 2; i >= 1; i--)
        downHeap(i);
}

void printHeap()
{
    for (int i = 1; i < n + 1; i++)
    {
        printf(" %d", H[i]);
    }
    puts("");
}

void main()
{
    int key, val;
    scanf("%d", &key);

    for (int i = 1; i < key + 1; i++)
    {
        scanf("%d", &val);
        H[i] = val;
        n++;
    }

    buildHeap();
    printHeap();
}