from unittest import skip


tmp = input().split()

a = int(tmp[0]) # fixed cost
b = int(tmp[1]) # variable cost
c = int(tmp[2]) # price of item

item_num = -1

try:
    item_num = a // (c - b)
except ZeroDivisionError:
    print("-1")
    exit(0)

if(item_num < 0):
    print(-1)
else:
    print(int(item_num) + 1)