#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// hanoi using recursion
void hanoi(int n, char from, char by, char to) {
    if (n == 1) {
        printf("1 : %c -> %c\n", from, to);
    } else {
        hanoi(n - 1, from, to, by);
        printf("%d : %c -> %c\n", n, from, to);
        hanoi(n - 1, by, from, to);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    return 0;
}