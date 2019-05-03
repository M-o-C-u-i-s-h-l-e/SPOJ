# will get TLE

def solve(i, j, k):
	if k == 0:
		return 0
	if i == -1 or j == -1:
		return -1
	key = (i, j, k)
	if key in d.keys():
		return d[key]
	first = -1
	if s1[i] == s2[j]:
		first = solve(i-1, j-1, k-1)
		if first != -1:
			first += ord(s1[i])
	sec = solve(i-1, j, k)
	thd = solve(i, j-1, k)
	d[key] = max(first, sec, thd)
	return d[key]

for _ in range(int(input())):
	s1 = input()
	s2 = input()
	k = int(input())
	d = {}
	res = solve(len(s1)-1, len(s2)-1, k)
	print(0) if res == -1 else print(res)
