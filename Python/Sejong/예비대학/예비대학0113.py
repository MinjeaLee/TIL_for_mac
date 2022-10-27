#실습 1번 문제
#나누기가 있는 문제는 제수 생각 할 것.
n1 = int(input())
n2 = int(input())
print("n1 + n2 = {}".format(n1 + n2))
print("n1 - n2 = {}".format(n1 - n2))
print("n1 * n2 = {}".format(n1 * n2))
print("n1 / n2 = {}".format(n1 / n2))


#실습 2번 문제
#나누기가 있는 문제는 제수 생각 할 것.
n1 = int(input())   
n2 = int(input())
print("n1 ** n2 = {}".format(n1 ** n2))
print("n1 // n2 = {}".format(n1 // n2))
print("n1 % n2 = {}".format(n1 % n2))

#실습 3번 문제
r = int(input())
pi = 3.14
print("Radius of circle = {}".format(r))
print("Length of circle = {}".format(2*pi*r))
print("Area of circle = {}".format(r**2*pi))

#실습 4번 문제
n1 = int(input())
n2 = int(input())
n1, n2 = n2, n1
print("After Swap\nn1 = {}\nn2 = {}".format(n1, n2))

#실습 5번 문제
#단, 계산시 발생하는 소수점은 버린다. 조건 확인. 결과값에 int달아주기.
price = int(input())
after = int(price - (price * 0.1))
print("before = {}\nafter = {}".format(price,after))

#실습 6번 문제
str_a = input()
str_b = input()
print("REsult = {}".format(str_a + str_b))

#실습 7번 문제
str_a = input()
times = int(input())
print("Result = {}".format(str_a*times))

#실습 8번 문제
name = input()
print("My name is {}.".format(name))
age = int(input())
print("I am {} years old.".format(age))
print("{}'s birth year is {}.".format(name, 2021 - age))

#실습 9번 문제
mul = int(input())
print("x {}".format(mul))
for i in range(1, 10):
    print("{} x {} = {}".format(mul, i ,mul * i))

#실습 10번 문제
#초를 분, 초로 변환하는 법 -> 분 : 초 / 60, 초 : 초 % 60
#공백 채우기 포멧 사용시 최소 공백만 입력하면 됨 ex) 02 -> {0:0>2}, 123 -> {0:0>2}
#{0:0>2}에서 :앞에있는 0은 포메팅 주소
# 만약 .format()을 사용하지 않는 다면 예를 들어 %02d. {0:0>2} = %02d
sec = int(input())
min = int(sec / 60)
sec_2 = sec % 60
print("Result = {0:0>2}:{1:0>2}".format(min, sec_2))

#실습 과제 1번 문제
sec = int(input())
sec_2 = sec % 60
min = int(sec/60 % 60)
hours = int(sec / 3600 % 24)
days = int(sec / 86400)
print("Result = {0} days {1:0>2}:{2:0>2}:{3:0>2}".format(days, hours, min, sec_2))


