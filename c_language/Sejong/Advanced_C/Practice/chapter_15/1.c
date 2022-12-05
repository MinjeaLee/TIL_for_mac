#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : -(a))

int main(){
	int arr[6];
	int max_abs = INT_MIN;
	int max_origin;

	for(int i = 0; i < 6; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < 6; i++){
		max_abs = MAX(max_abs, ABS(arr[i]));
	}
	max_origin = arr[0];
	for(int i = 0; abs(arr[i]) != max_abs; i++){
		max_origin = arr[i + 1];
	}

	printf("%d %d", max_origin, max_abs);

	return 0;
}