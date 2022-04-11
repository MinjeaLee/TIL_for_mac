# make func gcd(a, b) that returns the gcd value d of a and b
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# make func extended_gcd(a, b) that returns the gcd value d, two constants s and t which satisfy the equation d = s*a + t*b
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        d, s, t = extended_gcd(b, a % b)
        return d, t, s - (a // b) * t

print("gcd(45, 75) =", gcd(45, 75))
print("gcd(666, 1414) =", gcd(666, 1414))
print("gcd(102, 222) =", gcd(102, 222))
print("gcd(2**101+16, 2**202+8) =", gcd(2**101+16, 2**202+8))

print("extended_gcd(45, 75) =", extended_gcd(45, 75))
print("extended_gcd(666, 1414) =", extended_gcd(666, 1414))
print("extended_gcd(102, 222) =", extended_gcd(102, 222))
print("extended_gcd(2**101+16, 2**202+8) =", extended_gcd(2**101+16, 2**202+8))

