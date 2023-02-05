import sys

str = str(sys.stdin.readline()).strip()
dict = {}

for i in str:
	if 'a' <= i <= 'z':
		i = i.upper()
	if i in dict:
		dict[i] += 1
	else:
		dict[i] = 1

key_sort = list(dict.values())
key_sort.sort(reverse=True)
if len(dict) == 1:
	print(list(dict.keys())[0])
	exit(0)
if key_sort[0] == key_sort[1]:
	print("?")
else:
	for i in dict.items():
		if key_sort[0] == i[1]:
			print(i[0])