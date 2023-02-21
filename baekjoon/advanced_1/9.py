# 25206
import sys

grade_list = {'A+' : 4.5, 'A0' : 4.0, 'B+' : 3.5, 'B0' : 3.0, 'C+' : 2.5, 'C0' : 2.0, 'D+' : 1.5, 'D0' : 1.0, 'F' : 0.0}

total_grade = 0.0
total_credit = 0.0

for _ in range(20):
	name, credit, grade = sys.stdin.readline().split()
	if grade == 'P':
		continue
	total_credit += int(credit[0])
	total_grade += grade_list[grade] * int(credit[0])

print(total_grade / total_credit)