# 9506
import sys

def divisor(n):
	arr = []
	for i in range(1, n):
		if n % i == 0:
			arr.append(i)
	return arr

while True:
	n = int(sys.stdin.readline())
	if n == -1:
		break
	div = divisor(n)
	if n == sum(div):
		print(f"{n} = ", end= "")
		for i in div[:-1]:
			print(f"{i} + ", end= "")
		print(f"{div[-1]}")
	else:
		print(f"{n} is NOT perfect.")
