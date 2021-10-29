def GCD(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return 0
    if a % b == 0:
        return b
    else:
        return GCD(b , a%b)

a = int(input())
for i in range(2,a+1):
    