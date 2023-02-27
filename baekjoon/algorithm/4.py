# 24265

# MenOfPassion(A[], n) {
#   sum < - 0;
#    for i < - 1 to n - 1
#       for j < - i + 1 to n
#           sum < - sum + A[i] × A[j];  # 코드1
#     return sum;
# }

# n - 1 * 
import sys

n = int(sys.stdin.readline())
cnt = 0
# 1 * 2 3 4 5 6 7 : 6
# 2 * 3 4 5 6 7 : 5
# 3 : 4
# 4 : 3
# 5 : 2
# 6 : 1

for i in range(1, n):
	cnt += i

print(cnt)
print(2)