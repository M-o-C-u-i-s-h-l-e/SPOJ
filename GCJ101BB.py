for T in range(1, int(input())+1):
	n, k, b, t = map(int, input().split())
	p = list(map(int, input().split()))
	s = list(map(int, input().split()))
	Count = Sum = fail = 0
	for i in range(n-1, -1, -1):
		if b <= s[i] * t + p[i]:
			Count += 1
			Sum += fail
		else:
			fail += 1
		if Count == k:
			break
	st = str(Sum) if Count == k else "IMPOSSIBLE"
	print("Case #{}: {}".format(T, st))
