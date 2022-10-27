str = input()

num = [0 for i in range(26)]

for i in range(len(str)):
    try:
        num[ord(str[i]) - 97] += 1
    except:
        continue

for i in range(26):
    print("{}:{}".format(chr(i + ord('a')), num[i]))