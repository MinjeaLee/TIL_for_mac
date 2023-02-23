# 1978
import sys, math

def check_prime(x):
	if x == 1:
		return 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1

n = int(sys.stdin.readline())
count = 0
num = list(map(int, sys.stdin.readline().split()))
for i in num:
	if check_prime(i):
		count += 1
	
print(count)
	
