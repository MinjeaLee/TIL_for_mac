import random

name = ["우상민", "김우성", "지승훈", "조대종", "김재민", "임우협", "차한솔", "오현규", "서예린", "문지윤", "권수빈", "송민희", "진현준", "김민준", "표자연", "김홍현", "신정훈", "곽어진", "조해성", "이성원", "김혜정", "강민채", "양혜연", "백승혜",  "양인규"]

# 학생들을 랜덤으로 섞는다.
random.shuffle(name)

# 5조로 나눈다.
teams = [name[i:i+5] for i in range(0, len(name), 5)]

# 결과 출력
for idx, team in enumerate(teams, 1):
    print(f"팀 {idx}: {team}")


# NSbit x S! MT
# n * m = nm (n, m은 정수)
# 1 부터 10까지 출력 (for 문 사용)
# x, y, z 입력 받아서 제일 큰 수 출력
