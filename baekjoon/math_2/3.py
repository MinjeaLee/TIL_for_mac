# 11653
import sys
import sys, math

def check_prime(x):
	if x == 1:
		return 0
	for i in range(2, int(math.sqrt(x)) + 1):
		if x % i == 0:
			return 0
	return 1

n = int(sys.stdin.readline())
# n = int(sys.argv[1])

while n > 1:
	for i in range(2, n + 1):
		if check_prime(i) and n % i == 0:
			print(i)
			n //= i
			break

# chatgpt

n = int(sys.stdin.readline())

i = 2
while n > 1:
    if n % i == 0:
        n //= i
        print(i)
    else:
        i += 1
