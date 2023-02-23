# 1978
import sys
import math


def check_prime(x):
	if x == 1:
		return 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1


n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
flag = 0
total = 0
min_prime = -1

for i in range(n, m + 1):
	check = check_prime(i)
	if min_prime == -1 and check:
		flag = 1
		min_prime = i
		total += i
	elif check:
		total += i

if flag:
	print(f"{total}\n{min_prime}")
else:
	print(-1)
