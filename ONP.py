t = int(input())
while t:
	t -= 1
	s = input()
	st = list()
	for i in range(len(s)):
		if s[i] >= 'a' and s[i] <= 'z':
			print(s[i], end = "")
			continue
		if s[i] != ')':
			st.append(s[i])
			continue
		else:
			while st[len(st)-1] != '(':
				print(st[len(st)-1], end = "")
				st.pop()
			st.pop()
	print() 
