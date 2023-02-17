import sys

t = int(sys.stdin.readline())

for _ in range(t):
    k = int(sys.stdin.readline())  # 층
    n = int(sys.stdin.readline())  # 호수

    people = [[i for i in range(1, n+1)]]
    for i in range(1, k+1):
        row = [sum(people[i-1][:j+1]) for j in range(n)]
        people.append(row)

    print(people[k][n-1])
