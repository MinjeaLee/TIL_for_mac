#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int a[10];

	for(int i = 0; i < 10; i++){
		scanf("%d ", &a[i]);
		printf("------%d\n", a[i]);
	}

	return 0;
}