import random
def lotto_main(lotto_data):
    lotto_num = random.choice(lotto_data)
    return lotto_num

# 사용자 숫자 입력
k = 0
lotto_usernum = []
while k < 6:
    k += 1
    user_num = int(input("{}번 숫자 입력 : ".format(k)))
    lotto_usernum.append(user_num)

# 로또 번호 추첨
# n = 0
# lotto_numlist = []
# lotto_data = list(range(1,46))
# while n < 6:
#     n += 1
#     num = lotto_main(lotto_data)
#     lotto_numlist.append(num)
#     lotto_data.remove(num)
# lotto_numlist.sort()
# print(lotto_numlist)

# # 로또 등수 표시
# lotto_usernum = set(lotto_usernum)
# lotto_numlist = set(lotto_numlist)
# score = 7 - len(lotto_usernum & lotto_numlist)
# score_num = list(lotto_numlist & lotto_usernum)
# score_num.sort()
# print("{}등 일치 숫자 : {}".format(score, score_num))

# 1등 될때까지
no = 0
while True:
    no += 1
    n = 0
    lotto_numlist = []
    lotto_data = list(range(1,46))
    while n < 6:
        n += 1
        num = lotto_main(lotto_data)
        lotto_numlist.append(num)
        lotto_data.remove(num)
    lotto_numlist.sort()
    print(lotto_numlist)

    lotto_usernum = set(lotto_usernum)
    lotto_numlist = set(lotto_numlist)
    score = 7 - len(lotto_usernum & lotto_numlist)
    score_num = list(lotto_numlist & lotto_usernum)
    score_num.sort()
    print("{}등 일치 숫자 : {}".format(score, score_num))

    if score <= 2:
        print(no)
        break

#real lotto
import random 

k = 0
user_num_list = [] 
while k < 6:
    k += 1
    user_num = int(input())
    user_num_list.append(user_num)
print("user num : ", end='')
for l in user_num_list:
    print(l, end=' ')
print('')
num = 0
while True:
    num += 1
    lotto_num = random.sample(range(1,46), 6)
    lotto_num.sort()

    bonus_num_list = list(range(1,46))
    for i in lotto_num:
        bonus_num_list.remove(i)
    bonus_num = random.choice(bonus_num_list)

    print("lotto num : ", end='')
    for j in lotto_num:
        print(j, end=' ')
    print("+",bonus_num)

    if len(set(user_num_list) & set(lotto_num)) == 6:
        print("1등")
        a = 1
    elif len(set(user_num_list) & set(lotto_num)) == 4 and bonus_num in user_num_list:
        print("2등")
        a = 2
    elif len(set(user_num_list) & set(lotto_num)) == 5 and bonus_num not in user_num_list:
        print("3등")
        a = 3
    elif len(set(user_num_list) & set(lotto_num)) == 4 and bonus_num not in user_num_list:
        print("4등")
        a = 4
    elif len(set(user_num_list) & set(lotto_num)) == 3 and bonus_num not in user_num_list:
        print("5등")
        a = 5
    else:
        print("꽝")
        a = 6

    if a <= 3:
        print(num)
        break 
