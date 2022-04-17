#factorial
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def max_prime(n):
    if n == 1:
        return 1
    else:
        for i in range(2, n):
            if n % i == 0:
                return max_prime(n-1)
        return n

def is_prime(n):
    if n == 1:
        return False
    else:
        for i in range(2, n):
            if n % i == 0:
                return False
        return True

n = int(input("input a number: "))

Qn = factorial(n) + 1
qn = max_prime(Qn)

print("Qn = ", Qn)
print("qn = ", qn)
print("is_prime(qn) = ", is_prime(qn))