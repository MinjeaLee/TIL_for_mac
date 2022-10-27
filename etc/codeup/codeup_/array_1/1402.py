n = int(input())

a = []

nums = input().split()

#input
for i in range(n):
    a.append(nums[i])

# reverse
a.reverse()

for i in range(n):
    print(a[i], end=" ")