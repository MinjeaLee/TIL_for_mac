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

# lucas_lehmer_test(p): it tests whether the Mersenne number M_p = 2^p - 1 is prime or not 
# where p is a prime by using the Lucas-Lehmer test. 
# It outputs 1 if it is prime or 0 otherwise.

def lucas_lehmer_test(p):
    if p < 2:
        return 0
    if p == 2:
        return 1
    if p % 2 == 0:
        return 0

    m = 2 ** p - 1
    s = 4

    for i in range(p - 2):
        s = (s * s - 2) % m

    if s == 0:
        return 1
    else:
        return 0

# find_mersenne_primes(max): it prints all Mersenne primes from 3 to the Mersenne number M_{max} 
# by using the lucas_lehmer_test function and generate_all_primes function (in previous homework).
#  Note that it only prints primes p for M_p = 2^p - 1.

def find_mersenne_primes(max):
    for p in generate_all_primes(max):
        if p == 2:
            continue
        if lucas_lehmer_test(p):
            print(p)
    

print("lucas_lehmer_test(3) = {}".format(lucas_lehmer_test(3)))
print("lucas_lehmer_test(17) = {}".format(lucas_lehmer_test(17)))
print("lucas_lehmer_test(31) = {}".format(lucas_lehmer_test(31)))
print("lucas_lehmer_test(521) = {}".format(lucas_lehmer_test(521)))
print("lucas_lehmer_test(9689) = {}".format(lucas_lehmer_test(9689)))
print("lucas_lehmer_test(9697) = {}".format(lucas_lehmer_test(9697)))
print("----------find_mersenne_primes(5000)----------")
find_mersenne_primes(5000)
