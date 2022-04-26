n = int(input())

original = [i for i in range(1, n + 1)]
input_nums = []

for i in range(n - 1):
    input_nums.append(int(input()))

for i in input_nums:
    original.remove(i)

print(original[0])
