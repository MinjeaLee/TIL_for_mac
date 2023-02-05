#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(char *n){
	int result = 0;
	int pow = 100;
	
	for(int i = 0; i < 3; i++){
		result += (n[2 - i] - '0') * pow;
		pow /= 10;
	}

	return result;
}

int main(){
	char str[5], str2[5];
	int result_1, result_2;

	scanf("%s %s", str, str2);
	result_1 = cal(str);
	result_2 = cal(str2);

	if(result_1 > result_2){
		printf("%d", result_1);
	}
	else{
		printf("%d", result_2);
	}

	

	return 0;
}