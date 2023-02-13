import sys

a, b, v = map(int, sys.stdin.readline().split())

day = (v - b) / (a - b)
if int(day) < day and day <= int(day) + 1:
	day = int(day) + 1
	print(day)
	exit()
else:
	print(int(day))
