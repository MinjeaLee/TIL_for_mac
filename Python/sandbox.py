import sys
from collections import deque

s, t = map(int, input().split())
if s == t :
    print(0)
    sys.exit(0)

visited = set()
found = False

q = deque([(s,'')])
visited.add(s)
#// operation = ['*','+','-','/']

while q :
    now,operand = q.popleft()
    if now >= int(1e9):
        continue
    if now == t :
        print(operand)
        found = True
        break
    for i in ['*','+','-','/'] :
        if i == '*':
            new = now * now
        elif i == '+':
            new = now + now
        elif i == '-':
            new = now-now
        elif now != 0 and i =='/':
            new = now/now

        if new not in visited :
            visited.add(new)
            q.append((new,operand+i))

if not found :
    print(-1)
    
