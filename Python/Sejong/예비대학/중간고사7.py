x = 0
y = 0
score = 0
x_2 = int(input())
y_2 = int(input())
x__2 = int(input())
y__2 = int(input())
x_c = int(input())
y_c = int(input())
goal = int(input())
while score < goal:
    head = input()
    if head == 'UP':
        y += 1
    elif head == "DOWN":
        y -= 1
    elif head == "LEFT":
        x -= 1
    elif head == "RIGHT":
        x += 1
    elif head == "LEFTUP":
        x -= 1
        y += 1
        pass
    elif head == "LEFTDOWN":
        x -= 1
        y -= 1
        pass
    elif head == 'RIGHTUP':
        x += 1
        y += 1
    elif head == "RIGHTDOWN":
        x += 1
        y -= 1
    else:
        continue
    print("X = {} Y = {} SCORE = {}".format(x, y, score))
    if x == x_c and y == y_c:
        x, y = 0, 0
        print("X = {} Y = {} SCORE = {}".format(x, y, score))
    elif x == x_2 and y == y_2:
        score += 2
        print("X = {} Y = {} SCORE = {}".format(x, y, score))
    elif x == x__2 and y == y__2:
        score -= 2
        print("X = {} Y = {} SCORE = {}".format(x, y, score))
    elif x == 0 and y == 0:
        pass
    elif x * y > 0:
        score += 1
        print("X = {} Y = {} SCORE = {}".format(x, y, score))
    elif x*y <= 0:
        score -= 1
        print("X = {} Y = {} SCORE = {}".format(x, y, score))
    
        

