#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int hi(int a, ...){
	va_list ap;
	int i;
	va_start(ap, a);
	for(i = 0; i < a; i++){
		printf("%d ", va_arg(ap, int));
	}ㅁㅁ
	va_end(ap);
	return 0;
}

int main(){

	hi(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, \
	12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, \
	25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39);
	

	return 0;
}