import sys

n = int(sys.stdin.readline())
tmp = n
min_c = 9999999
flag = 0
c_5 = n // 5

for i in range(c_5 + 1):
	n = tmp
	n -= 5 * i
	c_3 = n // 3
	n -= 3 * c_3
	if n != 0:
		continue
	flag = 1
	if min_c > i + c_3:
		min_c = i + c_3

if flag:

	print(min_c)
else:
	print("-1")

# n -= 5 * c_8
# c_3 = n // 3
# n -= 3 * c_3
# if n:
# 	c_3 = tmp // 3
# 	tmp -= 3 * c_3
# 	if tmp:
# 		print(-1)
# 	else:
# 		print(c_3)
# else:
# 	print(c_8 + c_3)