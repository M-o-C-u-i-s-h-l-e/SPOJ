from collections import Counter

for _ in range(int(input())):
	s1 = input()[:-1]
	s2 = input()[:-1]
	c1 = Counter(s1)
	c2 = Counter(s2)
	ans = 100077
	for i in c1.keys():
		if i in c2.keys():
			ans = min(ans, c2[i] // c1[i])
		else:
			ans = 0
	print(ans)
