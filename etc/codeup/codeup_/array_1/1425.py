tmp = input().split()
n = int(tmp[0])
line_num = int(tmp[1])

tmp = input().split()
stu = [i for i in tmp]

stu.sort()

extra = n % line_num
non_extra = n // line_num

for i in range(non_extra):
    for j in range(line_num):
        print(stu[i * line_num + j], end=" ")
    print()

for i in range(n - extra, n):
    print(stu[i], end=" ")
