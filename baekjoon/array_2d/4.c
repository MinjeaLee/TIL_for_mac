// 2563
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int arr[100][100] = {0, };
	int n;
	int start_i, start_j;
	int cnt = 0;

	scanf("%d", &n);

	for(int l = 0; l < n; l++){
		scanf("%d %d", &start_i, &start_j);
		for(int i = start_i; i < start_i + 10; i++){
			for (int j = start_j; j < start_j + 10; j++){
				if(arr[i][j] == 0){
					arr[i][j] = 1;
				}
			}
		}
	}

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if (arr[i][j] == 1){
				cnt++;
			}
		}
	}

	printf("%d", cnt);


	return 0;
}