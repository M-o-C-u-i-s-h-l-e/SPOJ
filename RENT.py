import bisect as bs

for _ in range(int(input())):
	n = int(input())
	ls = []
	for i in range(n):
		temp = list(map(int, input().split()))
		ls.append(temp)
	ls.sort()
	s = [ls[i][0] for i in range(n)]
	d = [ls[i][1] for i in range(n)]
	c = [ls[i][2] for i in range(n)]
	dp = [0] * (n+1)
	for i in range(n-1, -1, -1):
		dp[i] = max(dp[i+1], dp[bs.bisect_right(s, s[i]+d[i])] + c[i])
	print(dp[0])
