#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
    plist->numOfData = 0;
    plist->curPosition = 0;
}

void LInsert(List * plist, LData data) {
    if(plist->numOfData >= LIST_LEN) {
        printf("List is full.\n");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
    if(plist->numOfData == 0) {
        printf("List is empty.\n");
        return FALSE;
    }
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List * plist, LData * pdata) {
    if(plist->curPosition >= plist->numOfData - 1) {
        printf("No more data.\n");
        return FALSE;
    }
    plist->curPosition++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List * plist) {
    int rpos = plist->curPosition;
    int numOfData = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos];
    for(i = rpos; i < numOfData - 1; i++) {
        plist->arr[i] = plist->arr[i + 1];
    }
    plist->numOfData--;
    plist->curPosition--;
    return rdata;
}

int LCount(List * plist) {
    return plist->numOfData;
}