import time
from turtle import st

start = time.time()
for a in range(1, 1000):
	for b in range(2, 1000):
		for c in range(3, 1000):
			if a + b + c == 1000:
				if a**2 + b**2 == c**2:
					print(a, b, c)
					print(a*b*c)
					print(time.time() - start)
					exit()
