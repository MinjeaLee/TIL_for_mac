import sys

t = int(sys.stdin.readline())

for i in range(t):
	h, w, n = map(int, sys.stdin.readline().split())

	if n <= h:
		print(f"{n}01")
		continue
	if n % h == 0:
		if len(str(n // h)) == 1:
			print(f"{h}0{n // h}")
		else:
			print(f"{h}{n // h}")
		continue
	
	result_w = n // h + 1

	if len(str(result_w)) == 1:
		print(f"{n % h}0{result_w}")
	else:
		print(f"{n % h}{result_w}")