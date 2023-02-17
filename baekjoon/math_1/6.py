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

# chatGPT 코드

t = int(sys.stdin.readline())

for _ in range(t):
    k = int(sys.stdin.readline())  # 층
    n = int(sys.stdin.readline())  # 호수

    people = [[i for i in range(1, n+1)]]
    for i in range(1, k+1):
        row = [sum(people[i-1][:j+1]) for j in range(n)]
        people.append(row)

    print(people[k][n-1])
# 나랑 무엇이 다른 지 잘 모르겠음,,,ㅠㅠ
#TODO : 무엇이 다른지 파악 -> 코드 수정