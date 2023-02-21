# 	10812
import sys

n, m  = map(int, sys.stdin.readline().split())

bucket = [i + 1 for i in range(n)]

for _ in range(m):
	i, j, k = map(int, sys.stdin.readline().split())
	new_bucket = []
	for l in range(k - 1, j):
		new_bucket.append(bucket[l])
	for l in range(i - 1, k - 1):
		new_bucket.append(bucket[l])
	new_bucket_index = 0
	for l in range(i - 1, j):
		bucket[l] = new_bucket[new_bucket_index]
		new_bucket_index += 1

for i in bucket:
	print(i, end=' ')