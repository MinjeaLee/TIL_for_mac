#include <stdio.h>

int main()
{
	int num1, num2;
	char pls;

	scanf("%d ", &num1);
	scanf("%d ", &num2);
	scanf("%c", &pls);

	switch (pls)
	{
	case '+':
		printf("%d + %d = %d", num1, num2, num1 + num2);
	case '-':
		printf("%d - %d = %d", num1, num2, num1 - num2);
	case '*':
		printf("%d * %d = %d", num1, num2, num1 * num2);
	case '/':
		printf("%d / %d = %d", num1, num2, num1 / num2);
	case '%':
		printf("%d %%  %d = %d", num1, num2, num1 % num2);
	}
	return 0; 
}