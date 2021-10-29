# 실습 1번 문제
n = int(input())as
k = 0
total = []
total_num = 0
while k < n:
    k +=1 
    num = int(input())
    if num > 0:
        total_num += num
    num = abs(num)
    total.append(num)
total.sort()
print(total)
print("Sum = {}".format(total_num))

# 실습 2번 문제
def cost(a):
    if a == "white":
        return 1000
    elif a == "yellow":
        return 2000
    elif a == 'blue':
        return 3000
    else:
        return 5000

people = int(input())
k = 0
while k < people:
    k += 1
    dish = int(input())
    l = 0
    total = 0
    while l < dish:
        l += 1
        color = input()
        total += cost(color)
    print("Total price = {}".format(total))    

# 실습 3번 문제
n = int(input())
k = 0
chart = {}
while k < n:
    k += 1
    city = input()
    people = int(input())
    dense = int(input())
    chart[city] = people / dense
value = list(chart.values())
keys = list(chart.keys())

print("Highest Population Density = {0}, {1:0.2f}".format(keys[value.index(max(value))], max(value)))

# 실습 4번 문제
n = int(input())
k = 0
chart = []
while k < n:
    k += 1
    kor =int(input())
    eng = int(input())
    math = int(input())
    ever = int((kor + eng + math) / 3)
    chart.append(ever)
print("Highest Avg : {}".format(max(chart)))
print("Lowest Avg : {}".format(min(chart)))

# 실습 5번 문제
student = {'Denis' : 60, 'Amin' : 70}
n = int(input())
k = 0
while k < n:
    k += 1
    name = input()
    score = int(input())
    student[name] = score

keys = list(student.keys())
values = list(student.values())
ever = sum(values) / len(keys)
print("Average : {0:0.2f}".format(ever))

# 실습 과제 1번 문제
num = int(input())
k = 0
chart = []
while k < num:
    k += 1
    kor = int(input())
    eng = int(input())
    math = int(input())
    chart.append((kor+eng+math)/3)
for i in range(0, len(chart)):
    print("Student{0} point = {1:0.2f}".format(i+1, chart[i]))
print("Highest Score Student = {}".format(chart.index(max(chart))+1))
print("Lowest Score Student = {}".format(chart.index(min(chart))+1))

# 과제 4 - 1 ************한번더 보기
num = int(input())
n = 0
for i in range(1,num+1):
    for j in range(i):
        n += 1
        print(n, end = '')
    print('')

# 실습 4 - 2
def cal_min(x):
    front = int(x[0:2])
    back = int(x[3:])
    result_min = back + (front * 60)
    return result_min 

def cal_time(a, b):
    result_min = cal_min(b) - cal_min(a)
    hour = result_min // 60
    min = result_min % 60 
    return hour, min

n = int(input())
k = 0
list = {}

while k < n:
    k += 1
    car_num = int(input())
    intime = input()
    outtime = input()
    value = cal_time(intime, outtime)
    list[car_num] = value

call_num = int(input())
if list.get(call_num) == None:
    print("None")
else:
    print("{}h {}m".format(list[call_num][0], list[call_num][1]))

#과제 4 - 3
list = {}
while True:
    char = input()
    if char == 'i':
        student_num = int(input())
        if len(str(student_num)) != 8:
            print("id error")
            continue
        name = input()
        grade = int(input())
        if grade > 5 or grade < 1:
            print("grade error")
            continue
        major = input()
        list[student_num] = name, grade, major
    elif char == "c":
        c_student_num = int(input())
        if list.get(c_student_num) == None:
            print("no id")
            continue
    
        option = int(input())
        if option == 1:
            after_name = input()
            list[c_student_num] = after_name, list[c_student_num][1], list[c_student_num][2]
        elif option == 2:
            after_grade = int(input())
            if after_grade > 5 or after_grade < 1:
                print("grade error")
                continue
            list[c_student_num] = list[c_student_num][0], after_grade, list[c_student_num][2]
        else:
            after_major = input()
            list[c_student_num] = list[c_student_num][0], list[c_student_num][1], after_major
        
    elif char == 'p':
        p_student_num = int(input())
        if list.get(p_student_num) == None:
            print("no id")
            continue
        print("id {} name is {}".format(p_student_num, list[p_student_num][0]))
        print("id {} entered the school in {}".format(p_student_num, "20"+str(p_student_num)[0:2]))
        print("id {} grade is {}".format(p_student_num, list[p_student_num][1]))
        print("id {} major is {}".format(p_student_num, list[p_student_num][2]))
    
    elif char == 'q':
        print("end")
        break
    
    else:
        print("no button")
