#실습 1번 문제
#꼭 다시풀기*********************************
a = [2,3,1,4]
print("a = ", a)
max = 0
for i in range(0 ,4):
    if a[i] > max:
        max = a[i]
    print(i, max)

print("Max = {}".format(max))


#실습 2번 문제
s = [8,6,9,10,4,7,10,6,8,7]
print("s ={}".format(s))
print("Max = {}".format(max(s)))
print("Idx = {}".format(s.index(max(s))))

#실습 3번 문제
n = int(input())
k = 0
a = []
while k < n:
    k += 1
    score = int(input())
    a.append(score)
print(a)
print("Avg = {0:0.2f}".format(sum(a)/n))

#실습 4번 문제
s = []
n = 0
while True:
    score = int(input())
    if score == 0:
        break
    s.append(score)
    n += 1
print(s)
print("Avg = {0:0.2f}".format(sum(s)/n))

#실습 5번 문제
n = int(input())
k = 0
p = [0,0,0]
while k < n:
    k += 1
    n1 = int(input())
    if n1 > p[0]:
        del p[0]
        p.insert(0, n1)
    n2 = int(input())
    if n2 > p[1]:
        del p[1]
        p.insert(1, n2)
    n3 = int(input())
    if n3 > p[2]:
        del p[2]
        p.insert(2, n3)
    print(p)
num = p.index(max(p))
print("Person{} Win".format(num+1))

#실습 6번 문제
score = [[90, 80, 100, 70, 80, 90, 100, 90], [60, 30, 90, 90, 85, 80, 75, 70], [85, 60, 99, 100, 90, 80, 70, 60]]
print("Min[0] = {}".format(min(score[0])))
print("Min[1] = {}".format(min(score[1])))
print("Min[2] = {}".format(min(score[2])))

#실습 7번 문제
n = int(input())
a = []
k = 0
for i in range(n):
    s_k, s_e, s_m = input().split()
    s_e = int(s_e); s_k = int(s_k); s_m = int(s_m)
    a.append([s_k, s_e, s_m])
    print("Student {0}'s Average Score : {1}".format(i+1, round(sum(a[i])/3, 2)))

#실습 8번 문제
a = (1, 2, 3, 4, 5)
n =  int(input())
b = a * n
c = b.count(3)
print("b = {}".format(b))
print("Number of 3 in b : {}".format(c))\

#실습 9번 문제
my_tuple = (1, 2, 3, 4, 5, 6, 7, 8, 9)
n = int(input())
m = int(input())
result = my_tuple[n : m]
print("Sliced tuple : {}".format(result)) 

#실습 10번 문제
myTuple = (1, 9, 7, 3, 2, 4, 8, 5, 6)
t = list(myTuple)
t.sort()
result = tuple(t)
print("resultTuple = {}".format(result))

#과제 3 - 1
n = int(input())
m = int(input())
k = 0
while k < n:
    k += 1
    if str(m) in str(k):
        for i in str(k):
            if i == str(m):
                print("clap!")
            else:
                pass
    else:
        print(k)
    
#과제 3 - 2
n1 = int(input())
n2 = int(input())
for j in range(1, 10):
    for i in range(n1, n2+1):
        print("{0} * {1} = {2:>2}\t".format(i, j, i*j), end = '')
    print('')

#과제 3 - 3
num = int(input())
list = []
kor = []
eng =[]
math = []
k = 0
while k < num:
    k += 1
    name = input()
    list.append(name)
    s_k = int(input())
    kor.append(s_k)
    s_e = int(input())
    eng.append(s_e)
    s_m = int(input())
    math.append(s_m)
    list.append([s_k, s_e, s_m])
highkor = kor.index(max(kor))+1
higheng = eng.index(max(eng))+1
highmath = math.index(max(math))+1
print("Korean high score = {}".format(list[(2*highkor-1)-1]))
print("{}'s Avg = {}".format(list[(2*highkor-1)-1], int(sum(list[(highkor*2)-1])/3)))
print("English high score = {}".format(list[(2*higheng-1)-1]))
print("{}'s Avg = {}".format(list[(2*higheng-1)-1], int(sum(list[(higheng*2)-1])/3)))
print("Math high score = {}".format(list[(2*highmath-1)-1]))
print("{}'s Avg = {}".format(list[(2*highmath-1)-1], int(sum(list[(highmath*2)-1])/3)))

#실습 과베 1번 문제
n = int(input())
k = 0
ever_list = []
total_list = []
while k < n:
    k += 1
    s_k = int(input())
    s_e = int(input())
    s_m = int(input())
    total_list.append([s_k, s_e, s_m])
    ever = sum(total_list[k-1]) / 3
    ever_list.append(ever)
    print("Student{0} point = {1:0.2f}".format(k, ever))
print("Highest Score Student = {}".format(ever_list.index(max(ever_list))+1))
