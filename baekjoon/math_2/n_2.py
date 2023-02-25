# 2501
import sys

def divisor(n):
	arr = []
	for i in range(1, n):
		if n % i == 0:
			arr.append(i)
		
	arr.append(n)
	return arr

n, k = map(int, sys.stdin.readline().split())

a = divisor(n)
# print(a)
if k > len(a):
	print("0")
else:
	print(a[k - 1])
