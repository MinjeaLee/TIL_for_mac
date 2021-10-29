#8번 문제
c1 = (1,2,3)
c2 = (4, )

print("Q8's answer is", c1 + c2)

#9번 문제

#10번 문제

a = {'a' : 90, 'b' : 80, 'c' : 70}
print("Q10's answer is ", a.get('b'))

#11번 문제
a = [1,1,1,2,2,3,3,3,4,4,5]
print("Q11's answer is ", list(set(a)))

#12번 문제
a = b = [1,2,3]
a[1] = 4
print("Q12's example is ", b)
print("Q12's answer is because a,b is same list")
c = [1,2,3]
d = c[:]
c[1] = 4
print(c,d)

