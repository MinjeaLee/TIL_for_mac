import sys

n = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
answer = [int(i) for i in tmp]

m = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
question = [int(i) for i in tmp]

for i in range(m):
    if answer.count(question[i]):
        print("1", end=" ")
    else:
        print("0", end=" ")