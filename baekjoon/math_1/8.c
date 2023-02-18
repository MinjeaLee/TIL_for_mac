#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str, int len){
	char temp;
	for (int i = 0; i < len / 2; i++){
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main(){
	char num_1[10002], num_2[10002];
	char *result;
	int cal_n;
	int len_1, len_2;
	int extra = 1;
	int carry = 0;

	int cal_num_1, cal_num_2;
	int result_index = 0;

	scanf("%s %s", num_1, num_2);

	len_1 = strlen(num_1);
	len_2 = strlen(num_2);
	cal_n = len_1 > len_2 ? len_2 : len_1;
	extra = len_1 > len_2 ? 1 : 2;
	result = (char *)malloc(sizeof(char) * (len_1 > len_2 ? len_1 + 2 : len_2 + 2));


	for (int i = 0; i < cal_n; i++){
		cal_num_1 = num_1[len_1 - i - 1] - '0';
		cal_num_2 = num_2[len_2 - i - 1] - '0';

		if (cal_num_1 + cal_num_2 + carry >= 10){
			result[result_index] = (cal_num_1 + cal_num_2 + carry) % 10 + '0';
			carry = 1;
		}
		else{
			result[result_index] = (cal_num_1 + cal_num_2 + carry) + '0';
			carry = 0;
		}
		result_index++;
	}
	// 나머지 처리
	if (extra == 1){
		for (int i = len_1 - cal_n - 1; i >= 0; i--){
			if (num_1[i] - '0' + carry >= 10){
				result[result_index] = (num_1[i] - '0' + carry) % 10 + '0';
				carry = 1;
			}
			else{
				result[result_index] = (num_1[i] - '0' + carry) + '0';
				carry = 0;
			}
			result_index++;
		}
	}
	else{
		for (int i = len_2 - cal_n - 1; i >= 0; i--){
			if (num_2[i] - '0' + carry >= 10){
				result[result_index] = (num_2[i] - '0' + carry) % 10 + '0';
				carry = 1;
			}
			else{
				result[result_index] = (num_2[i] - '0' + carry) + '0';
				carry = 0;
			}
			result_index++;
		}
	}
	if (carry){
		result[result_index] = '1';
		result_index++;
	}

	reverse(result, result_index);

	printf("%s", result);

	return 0;
}