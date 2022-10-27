#실습 1번 문제
n = int(input())
result = 1
for i in range(1, n+1):
    result *= i
print("Result =  {}".format(result))

#실습 2번 문제
n = int(input())
sum1 = 0
sum2 = 0
for i in range(1, n+1):
    if i % 2 == 0:
        sum2 += i
    else:
        sum1 += i
print("Sum1 = {}\nSum2 = {}".format(sum1, sum2))

#실습 3번 문제
n = int(input())
result = 0 
for i in range(n):
    result += n
print("Result = {}".format(result))

#실습 4번 문제
n1 = int(input())
n2 = int(input())
for i in range(n1, n2+1):
    for j in range(1, 10):
        print("{} X {} = {}".format(i, j, i * j))

#실습 5번 문제
n = int(input())
for i in range(0, n+1):
    for j in range(0, 60):
        print("{0:0>2}:{1:0>2}".format(i, j))

#실습 6번 문제
n = int(input())
for i in range(1, n+1):
    for j in range(n):
        print(i, end = '')
    print('')

#실습 7번 문제
def enlarge(a):
    if a > 0:
        return a + 1
    elif a < 0:
        return a - 1

n = int(input())
print(enlarge(n))

#실습 8번 문제
def multiply(n1,n2):
    return n1 * n2
def divide(n1, n2):
    return n1 / n2
n1 = int(input())
n2 = int(input())

print(multiply(n1, n2))
print(divide(n1, n2))

#실습 9번 문제 
def sum_digit(n):
    n = str(n)
    result = 0
    for i in n:
        i = int(i)
        result += i
    return result

n = int(input())
result = sum_digit(n)
print(result)

#실습 10번 문제
def get_gcd(n1, n2):
    if n1 < n2:
        n1, n2 = n2, n1
    if n2 == 0:
        return 0
    if n1 % n2 == 0:
        return n2
    else:
        return get_gcd(n2, n1 % n2)

n1 = int(input())
n2 = int(input())
print(get_gcd(n1, n2))

#실습 과제 1번 문제
def count_factors(a):
    count = 0
    for i in range(1, a+1):
        if a % i == 0:
            count += 1
        else:
            pass
    return count

n = int(input())
result = count_factors(n)
print("The number of factors of {} is {}.".format(n, result))

#과제 2 - 1
s1 = int(input())
s2 = int(input())
s3 = int(input())
d1 = int(input())
d2 = int(input())
d3 = int(input())
totals = s1 + s2 + s3
totald = d1 + d2 + d3
scores = totals % 3
scored = totald % 3

print("Sejong : %d\nDaeyang : %d" %(totals, totald))
if scores > scored:
    print("Winner : Sejong")
elif scores < scored:
    print("Winner : Daeyang")
else:
    print("Winner : None")

#과제 2 - 2
price = 0
count_a = 0
count_b = 0
count_c = 0
while True:
    num = int(input())
    if num == 1:
        count_a += 1
        price += 1500
    elif num == 2:
        count_b += 1
        price += 2000
    elif num == 3:
        count_c += 1
        price += 1000
    elif num == 4:
        print("Current sum : {}".format(price))
    elif num == 5:
        print("Ordered menu\nAmericano {}\nCafelatte {}\nCookie {}\nFinal sum : {}".format(count_a,count_b, count_c,price))
        break
    else:
        print("Wrong number")
        
#과제 3 - 3
input_coin = int(input())
price = int(input())
balance = input_coin - price
print("balance = {}".format(balance))
if balance >= 500:
    num_500 = balance // 500
    print("500won : {}".format(num_500))
    balance -= (500 * num_500)
else:
    pass
if balance >= 50:
    num_50 = balance // 50
    print("50won : {}".format(num_50))
    balance -= (50 * num_50)
else:
    pass
if balance >= 10:
    num_10 = balance // 10
    print("10won : {}".format(num_10))
    balance -= (10 * num_10)
else:
    pass
        


