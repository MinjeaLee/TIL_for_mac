# č	c=
#ć	c-
#dž	dz=
#đ	d-
#lj	lj
#nj	nj
#š	s=
#ž	z=
import sys

string = str(sys.stdin.readline()).rstrip()

alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

common = "cdz=-ljnjs"

cnt = 0

for i in range(len(string)):
	if not(string[i] in common):
		cnt += 1
		string = string[:i] + '0' + string[i+1:]
	
while True:
	check = 0
	for i in alpha:
		if i in string:
			check = 1
			cnt += 1
			index = string.find(i)
			string = string[:index] + '0' + string[index+len(i):]
			break
	if check == 0:
		for j in range(len(string)):
			if string[j] in common:
				check = 1
				cnt += 1
				string = string[:j] + '0' + string[j+1:]
				break
		
	if check == 0:
		break

print(cnt)



