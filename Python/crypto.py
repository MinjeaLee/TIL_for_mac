def cripto(a, n):
    result = ""
    for i in a:
        if ord(i) >= 65  and ord(i) <= 90:
            if ord(i) - n < 65:
                x = chr(ord(i)+ (26-n))
            else:
                x = chr(ord(i) - n)
            result += x
        else:
            result += i
    return result

text = 'LEDEVH HMDDC VIHYGI WIEVGL'
for i in range(1,26):
    print(cripto(text,i))
