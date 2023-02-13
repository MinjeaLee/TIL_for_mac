import sys

def check_index(str):
	index_list = []

	while True:
		check_char = "\n"
		for i in str:
			if i != "\n":
				check_char = i
				break
		if check_char == "\n":
			break
		index = []
		for i in range(len(str)):
			if str[i] == check_char:
				str = str[:i] + "\n" + str[i+1:]
				index.append(i)
		index_list.append(index)
	return index_list

def check_group(str):
	index = check_index(str)
	count = 0
	for i in range(len(index)):
		flag = 1
		for j in range(len(index[i]) - 1):
			if index[i][j + 1] - index[i][j] != 1:
				flag = 0
				return 0
	if flag == 1:
		return 1


# string = "123123"
n = int(sys.stdin.readline())
count = 0
for i in range(n):
	string = str(sys.stdin.readline()).strip()
	flag = check_group(string)
	if flag == 1:
		count += 1
# print(check_group("leeminjea"))
	
print(count)


# print(check_group(string))

