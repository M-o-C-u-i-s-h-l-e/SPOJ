for _ in range(int(input())):
	s1 = input()
	s2 = input()
	s1 = s1[:len(s1)-1]
	s2 = s2[:len(s2)-1]
	d1 = {}
	d2 = {}
	for i in s1:
		if i in d1.keys():
			d1[i] += 1
		else:
			d1[i] = 1
	for i in s2:
		if i in d2.keys():
			d2[i] += 1
		else:
			d2[i] = 1
	ans = 100077
	for i in d1.keys():
		c, val = i, d1[i]
		if c in d2.keys():
			ans = min(ans, d2[c] // val)
		else:
			ans = 0
	print(ans)
