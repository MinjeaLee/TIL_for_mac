# gcd 
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        (g, x, y) = extended_gcd(b, a % b)
        return (g, y, x - (a // b) * y)

a = int(input("input a : "))
b = int(input("input b : "))

print(gcd(a, b))
print("----------------")
print(extended_gcd(a, b))