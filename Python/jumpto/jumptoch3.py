#1번문제
a = "Life is too short, you need python"

if 'wife' in a:
    print("wife")
elif "python" in a and "you" not in a:
    print("python")
elif "need" in a:
    print("need")
else:
    print("none")

print("Q1's answer is output is need")

#2번문제 

i = 0
total = 0

while i <= 1000:
    i += 1
    if i % 3 == 0:
        total += i

print("Q2's answer is ",total)

#3번문제 

o = 0
print("Q3's answer is ")
while o < 5:
    o += 1
    print('*' * o)

#4번 문제
print("Q4's answer is ")
for p in range(1, 101):
    print(p, end=' ')
print(' ')

#5번 문제
chart = [70, 60, 55, 75, 95, 90, 80, 80, 85, 100]
score = 0    
for k in chart:
    score += k
ever = score / len(chart)
print("Q5's answer is ",ever)

