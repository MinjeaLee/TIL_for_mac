import sys

def sigma(k, n):
	l = []
	for i in range(0, n):
		l.append(sum(k[:i + 1]))
	return l

t = int(sys.stdin.readline())
for i in range(t):
	floor = [[i for i in range(1, 15)]]
	k = int(sys.stdin.readline()) # 층
	n = int(sys.stdin.readline()) # 호수 
	for j in range(1, k):
		floor.append(sigma(floor[j - 1], n))
	if k == 0:
		print(n)
	else:
		print(sum(floor[k - 1]))