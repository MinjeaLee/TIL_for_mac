#include <stdio.h>
#include <stdlib.h>
int main() {
  char *ptr = NULL;
  int idx;
  while (1) {
    printf("> ");
    scanf("%d", &idx);
    switch (idx) {
      case 1:
        if (ptr) {
          printf("Already allocated\n");
          break;
        }
        ptr = malloc(256);
        break;
      case 2:
        if (!ptr) {
          printf("Empty\n");
        }
        free(ptr);
        break;
      default:
        break;
    }
  }
}