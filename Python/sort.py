def sort(a):
    for i in range(len(a) -1):
        print('비교 1�? {}'.format(a[i]))
        for j in range(i+1, len(a)):
            if a[j] < a[i]:
                a[i],a[j] =a[j], a[i]
            print('비교 2�? {}'.format(a[i]))
    return a

print(sort([3,2,1]))