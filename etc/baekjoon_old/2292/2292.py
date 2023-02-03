num = int(input())

k = 1

while True:
    if num <= pow(k, 2) * 3 - 3 * k + 1:
        print(k)
        exit(0) 
    
    k += 1