# 24267

# MenOfPassion(A[], n) {
#     sum < - 0
#     for i < - 1 to n - 2
#     for j < - i + 1 to n - 1
#     for k < - j + 1 to n
#     sum < - sum + A[i] × A[j] × A[k]  # 코드1
#     return sum
# }

# i : 1
# 	j : 2
# 		k : 3 4 5 6 7 -> 5
# 	j : 3
# 		k : 4 5 6 7 -> 4
# 	j : 4
# 		k : 5 6 7 -> 3
# 	j : 5
# 		k : 6 7 -> 2
#	j : 6
#		k : 7 -> 1

# i : 2
# 	j : 3
# 		k -> 4
# 	j : 4 
# 		k -> 3
# 	j : 5
# 		k -> 2

# i : 3
# ...

# N -> 7
# 1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4, 1 + 2 + 3 + 4 + 5

# an : 1, 3, 6, 10, 15
# bn :   2  3  4  5
# 이러한 계차순열의 N - 2번째 항 까지의 합 -> 실행횟수

# 계차수열
# an = a1 + sigma(1, n - 1, bn)
# sigma(1, n - 1, bn) -> {(n - 1)n} / 2 + n - 1
# an = {(n - 1)n} / 2 + n -> (n^2 - n) / 2 + n

# sig(1, N - 2, an)
# -> {(n - 2)(n - 1)(2n - 3)} / 12 - {(n - 2)(n - 1)} / 4 + {(n - 2)(n - 1)} / 2

import sys

def check(n):
	cnt = 0
	for i in range(1, n - 1):
		for j in range(i + 1, n):
			for k in range(j + 1, n + 1):
				# print(f"i : {i} j : {j} k : {k}")
				cnt += 1

	return cnt


n = int(sys.stdin.readline())
# print(check(n))
print(int(((n - 2) * (n - 1) * (2 * n - 3)) / 12 - ((n - 2) * (n - 1)) / 4 + ((n - 2) * (n - 1)) / 2))
print(3)
