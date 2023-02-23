# 11653

import sys, math

def check_prime(x):
	if x == 1:
		return 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1

# prime_nums = []
n = int(sys.stdin.readline())
# for i in range(2, n + 1):
# 	if check_prime(i):
# 		prime_nums.append(i)
	
# print(prime_nums)

while n != 1:
	flag = 0
	for i in range(2, n + 1):
		if check_prime(i):
			if n % i == 0:
				print(i)
				n //= i
				flag = 1
		if flag:
			break
	# for i in prime_nums:
	# 	if n % i == 0:
	# 		print(i)
	# 		n //= i
	# 		break