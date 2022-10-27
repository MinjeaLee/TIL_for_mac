# str = input()

# open = str.count('(')

# close = str.count(')')

# print(open, close)

str = input()

strlen = len(str)

slice = []

open = 0
close = 0

for i in range(strlen):
    slice.append(str[i])

for i in range(strlen):
    if slice[i] == '(':
        open += 1
    elif slice[i] == ')':
        close += 1

print(open, close)