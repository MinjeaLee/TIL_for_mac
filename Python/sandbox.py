import sys

def Eratos(n):
    num = [i for i in range(n + 1)]
    num[1] = 0
    for i in range(2, n + 1):
        if num[i] == 0:
            continue
        for j in range(2 * i, n + 1, i):
            num[j] = 0
    
    result = []
    for i in num:
        if i != 0:
            result.append(i)
    return result


def min_diff(arr):
    arr_len = len(arr)
    if arr_len <= 2:
        return 0
    min_d = 99999
    idx = 0
    for i in range(arr_len):
        diff = arr[i][1] - arr[i][0]
        if diff < 0:
            continue
        if diff < min_d:
            min_d = diff
            idx = i
    return idx


n_cases = int(sys.stdin.readline())
for _ in range(n_cases):
    num = int(sys.stdin.readline())
    result = []
    primes = Eratos(num)
    for i in primes:
        a = []
        if primes.count(num - i):
            a.append(i)
            a.append(num - i)
            result.append(a)
    idx = min_diff(result)
    print(f"{result[idx][0]} {result[idx][1]}")