floor = int(input())
k = 0
while k < floor:
    k += 1
    for i in range(0, int((((2*floor-1)-(2*k-1))/2)+1)):
        print(" ", end ='')
    for j in range(0, (2*k-1)):
        print("*", end = '')
    print("")    

