# 9020
import sys


def eratosthenes(n):
    nums = [i for i in range(2, n+1)]
    primes = []
    while nums:
        p = nums[0]
        primes.append(p)
        nums = [x for x in nums if x % p != 0]
    return primes

def min_diff(arr):
	arr_len = len(arr)
	if arr_len <= 2:
		return 0
	min_diff = 99999
	idx = 0
	for i in range(arr_len):
		diff = arr[i][1] - arr[i][0]
		if diff < 0:
			continue
		if diff < min_diff:
			min_diff = diff
			idx = i
	return idx


T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	result = []
	flag = 0
	# primes = Eratos(n)
	primes = eratosthenes(n)
	for i in primes:
		a = []
		if primes.count(n - i):
			a.append(i)
			a.append(n - i)
			result.append(a)
	idx = min_diff(result)
	print(f"{result[idx][0]} {result[idx][1]}")
