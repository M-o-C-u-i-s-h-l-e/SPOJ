t = int(input())
while t:
	t -= 1
	n = int(input())
	ls = list(map(int, input().split()))
	s1, s2 = -1, -1
	for i in range(n-1, 0, -1):
		if ls[i] > ls[i-1]:
			s1 = i - 1
			break
	if s1 != -1:
		for i in range(n-1, s1, -1):
			if ls[i] > ls[s1]:
				s2 = i
				break
		ls[s1], ls[s2] = ls[s2], ls[s1]
		ls[s1+1: ] = sorted(ls[s1+1: ])
		for i in ls:
			print(i, end = "")
		print()
	else:
		print(-1)
