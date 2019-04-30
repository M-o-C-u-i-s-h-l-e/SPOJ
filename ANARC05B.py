def __bsearch(ls, key):
	l, r = 0, len(ls)-1
	while l <= r:
		m = l + (r - l) // 2
		if ls[m] == key:
			return m
		if ls[m] < key:
			l = m + 1
		else:
			r = m - 1
	return -1

while True:
	a = list(map(int, input().split()))
	n = a[0]
	a.pop(0)
	if n == 0:
		break
	b = list(map(int, input().split()))
	m = b[0]
	b.pop(0)
	a, b = set(a), set(b)
	ls = set()
	ls = a.intersection(b)
	a, b, ls = sorted(list(a)), sorted(list(b)), sorted(list(ls))
	if len(ls) == 0:
		print(max(sum(a), sum(b)))
		continue
	a1, b1 = __bsearch(a, ls[0]), __bsearch(b, ls[0])
	s1, s2 = sum(a[:a1]), sum(b[:b1])
	ans = max(s1, s2)
	for i in range(1, len(ls)):
		a1, a2 = __bsearch(a, ls[i-1]), __bsearch(a, ls[i])
		b1, b2 = __bsearch(b, ls[i-1]), __bsearch(b, ls[i])
		s1, s2 = sum(a[a1+1:a2]) + ls[i-1], sum(b[b1+1:b2]) + ls[i-1]
		ans += max(s1, s2)
	a1, b1 = __bsearch(a, ls[-1]), __bsearch(b, ls[-1])
	s1, s2 = sum(a[a1+1:]) + ls[-1], sum(b[b1+1:]) + ls[-1]
	ans += max(s1, s2)
	print(ans)
