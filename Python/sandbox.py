import sys

def reverse(arr, start, end):
    cnt = end - start
    if cnt % 2 != 0:
        cnt = cnt // 2 + 1
    else:
        cnt = cnt // 2
    
    for i in range(cnt):
        arr[start - 1], arr[end - 1] = arr[end - 1], arr[start - 1]
        start += 1
        end -= 1

n, m = map(int, sys.stdin.readline().split())

bucket = [i + 1 for i in range(n)]

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    reverse(bucket, i, j)

for i in bucket:
    print(i, end = " ")
