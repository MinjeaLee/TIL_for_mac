def eratosthenes(n):
    nums = [i for i in range(2, n+1)]
    primes = []
    while nums:
        p = nums[0]
        primes.append(p)
        nums = [x for x in nums if x % p != 0]
    return primes

print(eratosthenes(100))