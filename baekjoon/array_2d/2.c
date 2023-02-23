// 2566
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int num[9][9];
	int max = -1;
	int max_i, max_j;

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d", &num[i][j]);
		}
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if (num[i][j] > max){
				max = num[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	
	printf("%d\n%d %d", max, max_i + 1, max_j + 1);

	return 0;
}