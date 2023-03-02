import sys

n, k = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

for i in range(n - 1):
	for j in range(i + 1, n):
		if arr[j] > arr[i]:
			arr[j], arr[i] = arr[i], arr[j]
		
print(arr[k - 1])