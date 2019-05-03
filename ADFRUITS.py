v1 = [False] * 107
v2 = [False] * 107
arr = [[0 for j in range(107)] for i in range(107)]

def pre():
	for i in range(n):
		v1[i] = False
	for j in range(m):
		v2[j] = False
	for i in range(n+1):
		arr[i][0] = 0
	for i in range(m+1):
		arr[0][i] = 0
	for i in range(1, n+1):
		for j in range(1, m+1):
			if s1[i-1] == s2[j-1]:
				arr[i][j] = arr[i-1][j-1] + 1
			else:
				arr[i][j] = max(arr[i-1][j], arr[i][j-1])
	x, y = n, m
	while x > 0 and y > 0:
		if s1[x-1] == s2[y-1]:
			v1[x-1] = True
			v2[y-1] = True
			x -= 1
			y -= 1
		else:
			if arr[x-1][y] >= arr[x][y-1]:
				x -= 1
			else:
				y -= 1

while True:
	try:
		s1, s2 = input().split()
	except:
		break
	n, m = len(s1), len(s2)
	pre()
	res = list()
	i, j = 0, 0
	while i < n and j < m:
		k, l = i, j
		while k < n and not v1[k]:
			res.append(s1[k])
			k += 1
		while l < m and not v2[l]:
			res.append(s2[l])
			l += 1
		while k < n and l < m and v1[k] and v2[l] and s1[k] == s2[l]:
			res.append(s1[k])
			k += 1
			l += 1
		i, j = k, l
	while i < n:
		res.append(s1[i])
		i += 1
	while j < m:
		res.append(s2[j])
		j += 1
	print(*res, sep = "")
