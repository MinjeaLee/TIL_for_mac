import sys


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


def get_nearby_primes(n):
    # 중앙값을 구합니다.
    mid = n // 2


    # 중앙값에서부터 작은 수와 큰 수를 번갈아가며 소수를 찾습니다.
	#! 왜 중앙 값으로 부터 같은 거리인 i가 떨어져 있냐면?
	#! 두수의 합은 n이어야하고 n // 2와 두수의 평균값은 같아야한다.
	#! 따라서 중앙값으로 부터 같은 거리에 떨어진 친구들이 소수인지를 확인
	#! n = p1 + p2
	#!n = (n // 2 - i) + (n // 2 + i)
	#!n = n
    for i in range(0, mid+1):
        # 중앙값보다 작은 소수를 찾습니다.
        if is_prime(mid-i):
            # 중앙값보다 큰 소수를 찾습니다.
            if is_prime(mid+i):
                return (mid-i, mid+i)
    return None


t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    p1, p2 = get_nearby_primes(n)
    print(p1, p2)
