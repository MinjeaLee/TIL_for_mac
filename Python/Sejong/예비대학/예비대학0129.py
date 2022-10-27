#실습 1번 문제
user_info = { 'id':'software', 'pw':'python' }
id_ = input()
pw_ = input()
if id_ != user_info.get('id') and pw_ == user_info.get('pw'):
    print("ID Mismatch!")
elif id_ == user_info.get('id') and pw_ != user_info.get('pw'):
    print("PW Mismatch!")
else:
    print("Success in Login")

#실습 2번 문제
user_info = { 'name':'David', 'age':21, 'address':'Gwangjin-gu, Seoul' }
str = input()
if user_info.get(str) != None:
    print("{} : {}".format(str, user_info[str]))
else:
    print("The info does not exist!")

#실습 3번 문제
n = int(input())
k = 0
user_info = { 'name':'David', 'age':21, 'address':'Gwangjin-gu, Seoul' }
while k < n:
    k += 1
    print("Edit #{}".format(k))
    key = input()
    val = input()
    user_info[key] = val
keys = list(user_info.keys())
vals = list(user_info.values())
print("USER INFO")
for i in range(len(keys)):
    print("{} : {}".format(keys[i], vals[i]))

#실습 4번 문제
n = int(input())
k = 0
dic = {}
while k < n:
    k += 1
    name = input()
    score = int(input())
    dic[name] = score

name_ = input()
print("{}'s score = {}".format(name_, dic[name_]))

#실습 5번 문제
dic = {}
while True:
    num = int(input())
    if num == 1:
        name = input()
        score = int(input())
        dic[name] = score
    elif num == 2:
        name_2 = input()
        if name_2 in dic:
            print("Name = {}, Score = {}".format(name_2, dic[name_2]))
        else:
            print("No student")
    else:
        break

#실습 6번 문제
menu = {'white' : 1000, 'blue' : 3000, 'yellow' : 2000, 'red': 5000}
total = 0
while True:
    color = input()
    if color in menu:
        total += menu[color]
    else:
        break
print("Total price = {}".format(total))

#실습 7번 문제
n = int(input())
k = 0
t_s, t_o, t_d = 0, 0, 0
dic = {'sw' :t_s, 'os' : t_o, 'db' : t_d}
while k < n:
    k += 1
    sw, os, db = input().split()
    sw = int(sw); os = int(os); db = int(db)
    t_s += sw; t_o += os; t_d += db 
    dic['sw'] = t_s; dic['os'] = t_o; dic['db'] = t_d
print("Average(SW) = {}".format(int(dic['sw']/n)))
print("Average(OS) = {}".format(int(dic['os']/n)))
print("Average(DB) = {}".format(int(dic['db']/n)))

#실습 8번 문제
menu = {'salmon roe' : 1000, 'red sea bream' : 3000, 'egg roll': 1000, 'shrimp' : 2000, 'kimbab' : 1000, 'tuna' : 5000}
n = int(input())
k = 0
total = 0
while k < n:
    k += 1
    dish = input()
    total += menu[dish]

print("Total price = {}".format(total))

#실습 9번  문제
list_SW = []
k = 0
while k < 8:
    k += 1
    score = int(input())
    list_SW.append(score)
list_SW.sort()
list_SW.reverse()
for i in list_SW:
    print(i)

#실습 10번 문제
Grade = [
['C', 'B', 'A', 'C', 'D'],
['F', 'D', 'C', 'D', 'B'],
['A', 'B', 'A', 'B', 'A'],
['A', 'A', 'B', 'C', 'D'],
['B', 'B', 'B', 'B', 'B'],
['B', 'B', 'C', 'D', 'F'],
['C', 'A', 'A', 'A', 'A'],
['D', 'A', 'A', 'C', 'F']
]

def scan_grade(a):
    if a == "A":
        return 4.0
    elif a == "B":
        return 3.0
    elif a == "C":
        return 2.0
    elif a == "D":
        return 1.0
    else:
        return 0.0

num = 0  
for i in Grade:
    num += 1
    total = 0
    h = 0
    for j in i:
        h += 1  
        if h == 1 or h == 2 or h == 3:
            total += (scan_grade(j) * 3)
        elif h == 4:
            total += (scan_grade(j) * 2)
        else:
            total += scan_grade(j)
    print("{0} {1:0.2f}".format(num, total/ 12))

#10번 누나가 푼거
Grade = [
['C', 'B', 'A', 'C', 'D'],
['F', 'D', 'C', 'D', 'B'],
['A', 'B', 'A', 'B', 'A'],
['A', 'A', 'B', 'C', 'D'],
['B', 'B', 'B', 'B', 'B'],
['B', 'B', 'C', 'D', 'F'],
['C', 'A', 'A', 'A', 'A'],
['D', 'A', 'A', 'C', 'F']
]

def scan_grade(a):
    if a == "A":
        return 4.0
    elif a == "B":
        return 3.0
    elif a == "C":
        return 2.0
    elif a == "D":
        return 1.0
    else:
        return 0.0

for i in range(len(Grade)):
    
    total = 0
    for l in range(len(Grade[i])):
        if l == 0 or l == 1 or l == 2:
            total += scan_grade(Grade[i][l])*3
        elif l == 3:
            
            total += scan_grade(Grade[i][l])*2
        else:
            total += scan_grade(Grade[i][l])
    print("{0} {1:0.2f}".format(i+1, (total/12)))


#실습 과제 1번 문제
dic = {}
n = int(input())
k = 0
while k < n:
    k += 1
    name = input()
    height = int(input())
    weight = int(input())
    bmi = weight / ((height / 100) **2)
    dic[name] = bmi
val = list(dic.values())
key = list(dic.keys())
a = val.index(min(val))
print("Min BMI Member : {}, {}".format(key[a], int(val[a])))