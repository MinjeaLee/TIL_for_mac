import sys

dial = {"ABC" : 3, "DEF" : 4, "GHI" : 5, "JKL" : 6, "MNO" : 7, "PQRS" : 8, "TUV" : 9 , "WXYZ" : 10}

string = str(sys.stdin.readline()).strip()
time = 0

for i in string:
	for j in list(dial.keys()):
		if i in j:
			time += dial[j]
			continue

print(time)