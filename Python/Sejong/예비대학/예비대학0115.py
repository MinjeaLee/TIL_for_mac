#실습 1번 문제
n1 = int(input())
n2 = int(input())
if n1 > n2:
    n1, n2 = n2, n1
print("n1 = {}, n2 = {}".format(n1, n2))

#실습 2번 문제
n1 = int(input())
n2 = int(input())

if n1 >= n2:
    print("n1 >= n2")
    print(n2, n1)
else:
    print("n1 < n2")
    print(n1, n2)

#실습 3번 문제
list_a = []
n1 = int(input())
list_a.append(n1)
n2 = int(input())
list_a.append(n2)
n3 = int(input())
list_a.append(n3)
list_a.sort()
print("Min = {}".format(list_a[0]))
#############중간고사 필독 최소값 정석
n1 = int(input())
n2 = int(input())
n3 = int(input())

min  = n1
if n2 < min:
    min = n2
if n3 < min: #elif나 else를 쓰면 안됨. 하나하나 비교하므로
    min = n3
print(min)
#최댓값 구하기
n1 = int(input())
n2 = int(input())
n3 = int(input())
max = n1
if max < n2:
    max = n2
if max < n3:
    max = n3
print(max)

#실습 4번 문제
n1 = int(input())
n2 = int(input())
sum = n1 + n2 
if sum > 5 and sum < 10:
    print("5 < sum < 10 ")
elif sum <= 5:
    print("sum <= 5")
else:
    print("sum >= 10")

#실습 5번 문제
n1 = int(input())
n2 = int(input())

if n1 % 2 == 1 and n2 % 2 == 1:
    print("All dices are odd!")
elif n1 % 2 == 0 and n2 % 2 == 0:
    print("All dices are even!")
else:
    pass

#실습 6번 문제
str = input()
times = int(input())
print("String = {}".format(str * times))
#while문 사용해서풀어보기
#
str = input()
times = int(input())
res = ''
n = 0
while n < times:
    n += 1
    res += str
print("String = {}".format(res))
#for문 사용해서 풀어 보기


#실습 7번 문제
total = 0
times = 0
while True:
    n = int(input())
    if n == 4:
        times += 1
        total += n
        break
    else:
        times += 1
        total += n
print("Count= {}, Total = {}".format(times, total))

#실습 8번 문제
n = int(input())
result = 1
times = 0
while True:
    times += 1
    result = result * times
    if result >= n:
        break
print("Num = {}\nTotal = {}".format(times, result))
#뭔가 for문 사용해서 풀 수 있지 않을까

#실습 9번 문제
sum = 0
times = 0
while True:
    n = int(input())
    if n != 4:
        sum += n
        times += 1
    else:
        times += 1
        continue
    if sum >= 20:
        break
print("Count = {}\nTotal = {}".format(times, sum))

#실습 10번 문제
sum = 0
times = 0
while True:
    n = int(input())
    if n != 4:
        sum += n
        times += 1
    else:
        times += 1
        break
    if sum >= 20:
        break
print("Count = {}\nTotal = {}".format(times, sum))

#과제 1-1
name = input()
heighti = int(input())
height = heighti / 100
weight = int(input())
bmic = weight / (height**2)
bmi = round(bmic, 2) #round 쓰지 않고 해보기
print("{}'s BMI is {}".format(name, bmi))
#round 쓰지 않고 해보기
name = input()
height = int(input())/100
weight = int(input())
bmi = weight / (height ** 2)
print("{0}'s BMI is {1:0.2f}".format(name, bmi))


#과제 1-2
num_1 = int(input())
num_2 = input()
num_2_1 = int(num_2[0])
num_2_2 =int(num_2[1])
res_1 = num_1*num_2_2
res_2 = num_1*num_2_1
print("{}\n{}\n{}".format(res_1,res_2,(res_2*10)+res_1))

#실습 과제 1번 문제
str = list(input())
str.reverse()
result = ''
for i in str:
    result += i
print("Result = {}".format(result))

#리스트와 내장함수 쓰지 않고 풀어보기
n = list(input())
lenth = len(n)
result = ''
while lenth > 0:
    lenth -= 1
    spell = n[lenth]
    result += spell
print(result)

#*******와우 
num = input()
result = ''
for i in num:
    result = i + result # 이거 알아두기 !!!!!!!!!!!!!!

print(int(result))

