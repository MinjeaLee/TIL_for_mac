#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int t;
	int a, b, c;
	int x, y, z;
	int n; // number of couples

	//? x % y => 

	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		n = 0;
		for(x = 1; x <= a; x++){
			for(y = 1; y <= b; y++){
				for(z = 1; z <= c; z++){
					if(x % y == y % z && y % z == z % x){
						n++;
					}
				}
			}
		}
		printf("%d\n", n);
	}

	return 0;
}