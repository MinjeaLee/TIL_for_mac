// 10798
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str[5][16] = {0, };

	for (int i = 0; i < 5; i++){
		scanf("%s", str[i]);
	}

	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 5; j++){
			if (str[j][i] != '\0'){
				printf("%c", str[j][i]);
			}
		}
	}


	return 0;
}