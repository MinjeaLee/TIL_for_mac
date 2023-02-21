# 10988, palindrome
import sys

def check_palindrome(str):
	# 홀수
	str_len = len(str)
	mid = len(str) // 2
	if str_len % 2 != 0:
		for i in range(0, mid):
			if str[i] != str[str_len - i - 1]:
				return 0
	# 짝수
	else:
		for i in range(0, mid + 1):
			if str[i] != str[str_len - i - 1]:
				return 0
	
	return 1


string = sys.stdin.readline().strip()

print(check_palindrome(string))
