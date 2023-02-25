# 9020
import sys, math

def check_prime(x):
	if x == 1:
		return 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1

def min_diff(arr):
	arr_len = len(arr)
	if arr_len == 1:
		return 0
	min_diff = 99999
	idx = 0
	for i in range(arr_len):
		diff = arr[i][1] - arr[i][0]
		if diff < min_diff:
			min_diff = diff
			idx = i
	return idx

n = int(sys.stdin.readline())
for _ in range(n):
	num = int(sys.stdin.readline())
	primes = []
	flag = 0
	for i in range(2, num // 2 + 1):
		a = []
		if check_prime(i) and check_prime(num - i):
			a.append(i)
			a.append(num - i)
			primes.append(a)
	idx = min_diff(primes)
	print(f"{primes[idx][0]} {primes[idx][1]}")