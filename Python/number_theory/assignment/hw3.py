# factoring_simple(n): it returns the list of prime factors of n by using the simple division method.
def factoring_simple(n):
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n = n // 2
    for i in range(3, int(n ** 0.5) + 1, 1):
        while n % i == 0:
            factors.append(i)
            n = n // i
    if n > 2:
        factors.append(n)
    return factors


# factoring_fermat(n): it returns the two prime factors p and q of the given odd integer n by using the fermat factorization method where n = p*q.
def factoring_fermat(n):
    a = 2
    b = 2
    while b < n:
        if n % a == 0:
            b = n // a
            break
        a += 1
    return a, b


print(factoring_simple(11))
print(factoring_simple(100))
print(factoring_simple(12345))
print(factoring_simple(1000001))
print(factoring_simple(2**16))

print(factoring_fermat(15))
print(factoring_fermat(119))
print(factoring_fermat(187))
print(factoring_fermat(2987))
print(factoring_fermat(6750311))
