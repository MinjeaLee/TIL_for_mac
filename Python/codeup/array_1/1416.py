decimal = int(input())
binary = []

if decimal == 0:
    binary.append(0)

while 1:
    if decimal == 0:
        break
    binary.append(decimal % 2)
    decimal = decimal // 2

binary.reverse()

print(''.join(str(i) for i in binary))