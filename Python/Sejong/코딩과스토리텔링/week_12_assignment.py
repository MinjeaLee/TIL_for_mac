# 리스트 탐색, 정렬 실생활 예시
stu_chart = []

stu_num = int(input("학생 수를 입력하세요 : "))

for i in range(stu_num):
    name, height = input("이름과 키를 입력하세요 : ").split()
    stu_chart.append((name, int(height)))

for i in range(stu_num - 1):
    for j in range(i + 1, stu_num):
        if stu_chart[i][1] > stu_chart[j][1]:
            stu_chart[i], stu_chart[j] = stu_chart[j], stu_chart[i]

print("-----정렬 후 학생 키 출력-----")
for i in range(stu_num):
    print("{}. {} : {}".format(i + 1, stu_chart[i][0], stu_chart[i][1]))

