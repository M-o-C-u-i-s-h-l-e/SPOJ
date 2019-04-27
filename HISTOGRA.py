while True:
	ls = list(map(int, input().split()))
	n = ls[0]
	ls.pop(0)
	if n == 0:
		break
	st = list()
	i = Max = 0
	while i < n:
		if len(st) == 0 or ls[st[len(st)-1]] <= ls[i]:
			st.append(i)
			i += 1
		else:
			x = st[len(st)-1]
			st.pop()
			if len(st) == 0:
				temp = ls[x] * i
			else:
				temp = ls[x] * (i - st[len(st)-1] - 1)
			Max = max(Max, temp)
	while len(st) != 0:
		x = st[len(st)-1]
		st.pop()
		if len(st) == 0:
			temp = ls[x] * i
		else:
			temp = ls[x] * (i - st[len(st)-1] - 1)
		Max = max(Max, temp)
	print(Max)
