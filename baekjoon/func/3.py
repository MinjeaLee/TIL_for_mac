import sys

def judgement(n):
	num = [int(i) for i in str(n)]
	if len(num) <= 2:
		return 1
	diff = num[0] - num[1]
	for i in range(1, len(num) - 1):
		check = num[i] - num[i + 1]
		if diff != check:
			return -1
	return 1

n = int(sys.stdin.readline())
count = 0
	
for i in range(1, n + 1):
	if judgement(i) == 1:
		count += 1
# judgement(210)
print(count)
