# 양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 
# 예를 들어, d(75) = 75+7+5 = 87이
def functionD(n):
	if n > 10000:
		return -1
	# 123
	# 12
	sum = n
	for i in str(n):
		sum += int(i)
	return sum

num_arr = [i for i in range(1, 10001)]
# for i in range(1, 10001):
for i in range(1, 10001):
	num = i
	if num_arr[i - 1] == 0:
		continue
	while True:
		num = functionD(num)
		if num > 10000:
			break
		num_arr[num - 1] = 0

for i in num_arr:
	if i != 0:
		print(i)
