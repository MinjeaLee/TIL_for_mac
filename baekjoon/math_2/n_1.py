# 5086
import sys

def check_factor(x, y):
	if y % x == 0:
		return 1
	return 0

def check_multiple(x, y):
	if x % y == 0:
		return 2
	return 0

while True:
	x, y = map(int, sys.stdin.readline().split())
	if x == 0 and y == 0:
		break
	check = check_factor(x, y) + check_multiple(x, y)
	if check == 1:
		print("factor")
	elif check == 2:
		print("multiple")
	else:
		print("neither")
