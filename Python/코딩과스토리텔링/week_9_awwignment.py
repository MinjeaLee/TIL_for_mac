# for문 실생활 예시
print("평균 계산기")

chart = {} 

students_num = int(input("학생 수를 입력하세요 : "))
print("학생 이름과 점수를 입력하세요.\n입력형식) 홍길동 90")

for i in range(students_num):
    try:
        name, score = input("입력 : ").split()
        chart[name] = int(score)
    except:
        print("잘못된 입력입니다.")
        continue
        
total_score = 0
for name, score in chart.items():
    total_score += score

avg = float(total_score) / float(students_num)

select = input("성적 차트를 보시겠습니까? (y/n) : ")
if select == "y":
    print("성적 차트")
    for name, score in chart.items():
        print(name, score, sep="\t")

print("평균 점수는 {} 입니다.".format(avg))
