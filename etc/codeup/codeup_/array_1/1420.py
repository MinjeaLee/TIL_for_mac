n = int(input())

dic = {}
score = []
third = 0

for i in range(n):
    stu = input()
    tmp = stu.split()
    dic[tmp[0]] = int(tmp[1])
    score.append(int(tmp[1]))

score.sort()
score.reverse()

third = score[2]

items = dic.items()

for key, value in items:
    if value == third:
        print(key)