n = int(input())

num = [1, 1]

k = 1
while True:
    if n <= ((k ** 2 + k) / 2):
        if k % 2 == 1:
            num[1] = k
        else:
            num[0] = k
        break
    else:
        k += 1

if k % 2 == 1:
    for i in range(((k ** 2 + k) // 2) - n):
        num[0] += 1
        num[1] -= 1
else:
    for i in range(((k ** 2 + k) // 2) - n):
        num[0] -= 1
        num[1] += 1

print("{}/{}".format(num[0], num[1]))