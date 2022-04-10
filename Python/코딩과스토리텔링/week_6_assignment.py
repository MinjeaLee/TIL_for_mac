# k-mooc : 코딩과 스토리텔링 6주차 과제
menu = ["짜장면", "탕수육", "짬뽕", "양장피"]

print("welcome to sejong-won")

print("1 : 메뉴보기\n2 : 주문하기")
choice = int(input())

if(choice == 1):
    print("a : {}, b : {}, b : {}, c : {}".format(
        menu[0], menu[1], menu[2], menu[3]))

elif(choice == 2):
    print("주문하실 메뉴를 선택하세요.")
    order = input()
    if(order == 'a'):
        print("짜장면을 주문하셨습니다.")
    elif(order == 'b'):
        print("탕수육을 주문하셨습니다.")
    elif(order == 'c'):
        print("짬뽕을 주문하셨습니다.")
    elif(order == 'd'):
        print("양장피를 주문하셨습니다.")
    else:
        print("잘못된 입력입니다.")
else:
    print("잘못된 입력입니다.")