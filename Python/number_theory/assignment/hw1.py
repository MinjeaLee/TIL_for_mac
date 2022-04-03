import random

def is_prime(number):
    if number == 1:
        return 0
    for i in range(2, number):
        if number % i == 0:
            return 0
    return 1

def generate_all_primes(number):
    primes = []
    for i in range(2, number + 1):
        if is_prime(i):
            primes.append(i)
    return primes

def generate_random_primes(x, y):
    while True:
        p = random.randint(x, y)
        if is_prime(p):
            return p

print("is_prime(11) : {}".format(is_prime(11)))
print("is_prime(253) : {}".format(is_prime(253)))
print("is_prime(65537) : {}".format(is_prime(65537)))
print("generate_all_primes(50) : {}".format(generate_all_primes(50)))
print("generate_all_primes(100) : {}".format(generate_all_primes(100)))
print("generate_all_primes(1000) : {}".format(generate_all_primes(1000)))
print("generate_random_prime(2, 11) : {}".format(generate_random_primes(2, 11)))
print("generate_random_prime(100, 200) : {}".format(generate_random_primes(100, 200)))
print("generate_random_prime(1000, 2000) : {}".format(generate_random_primes(1000, 2000)))


