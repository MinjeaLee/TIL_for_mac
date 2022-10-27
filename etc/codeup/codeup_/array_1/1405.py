n = int(input())

nums = input().split()

for i in range(n):
    for j in range(n):
        print(nums[j], end=" ")
    print()
    tmp = nums.pop(0)
    nums.append(tmp)