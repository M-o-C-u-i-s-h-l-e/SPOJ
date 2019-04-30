n, x = map(int, input().split())
if 2 * x > (3 ** n) - 1:
	print(-1)
else:
	ls = []
	while x:
		ls.append(x % 3)
		x //= 3
	ls.append(0)
	for i in range(len(ls)-1):
		if ls[i] == 2:
			ls[i+1] += 1
			ls[i] = -1
		elif ls[i] == 3:
			ls[i+1] += 1
			ls[i] = 0
	for i in range(len(ls)):
		if ls[i] == -1:
			print(i+1, end = " ")
	print()
	for i in range(len(ls)):
		if ls[i] == 1:
			print(i+1, end = " ")
	print()
