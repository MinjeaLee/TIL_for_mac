#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int ft_num_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int ft_is_negative(int n, char *res)
{
	int flag;

	flag = 1;
	if (n < 0)
	{
		*res = '-';
		flag = -1;
	}
	return (flag);
}

char *ft_itoa(int n)
{
	char *res;
	int sign;
	int num;
	int i;

	i = ft_num_len(n) - 1;
	sign = 1;
	res = (char *)malloc(ft_num_len(n) + 1);
	if (res == NULL)
		return (NULL);
	res[ft_num_len(n)] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	sign = ft_is_negative(n, res);
	while (n)
	{
		num = n % 10;
		n /= 10;
		res[i--] = (num * sign) + '0';
	}
	return (res);
}

int main(){
	FILE *fp = fopen("1.txt", "w");
	clock_t start, end;
	double duration;
	char str[100];
	int i = 4;

	while (i < 10000){
		strcpy(str, "python3 7.py 1 ");
		strcat(str, ft_itoa(i));
		start = time(0);
		system(str);
		end = time(0);
		duration = (double) end - start;
		if (duration >= 2){
			fputs(str, fp);
		}
		printf("--------%lf---------%d\n", (double)end-start, i);
		i += 2;
	}
	

	return 0;
}