import sys

num = int(sys.stdin.readline())
# 먼저 주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수로 만들고, 각 자리의 숫자를 더한다.
# 그 다음, 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리 수를 이어 붙이면
# 새로운 수를 만들 수 있다.

if num < 10:
	result = num * 10 + num
else:
	sum = num // 10 + num % 10
	result = num % 10 * 10 + sum % 10
n = 1

while result != num:
	sum = result // 10 + result % 10
	result = result % 10 * 10 + sum % 10
	n += 1


print(n)
