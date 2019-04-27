for _ in range(int(input())):
	n = int(input())
	ls = sorted(list(map(int, input().split())))
	Count = 0
	for i in range(len(ls)):
		if ls[i] == 1:
			Count += 1
	for i in range(Count):
		print("1", end = " ")
	for i in range(Count):
		ls.pop(0)
	if len(ls) == 2 and ls[0] == 2 and ls[1] == 3:
		print("{} {}".format(2, 3))
	else:
		print(*ls[::-1], sep = " ")
