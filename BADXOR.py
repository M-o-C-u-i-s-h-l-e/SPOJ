# will get TLE

mod = int(1e8+7)

for t in range(1, int(input())+1):
	n, m = map(int, input().split())
	ls = list(map(int, input().split()))
	b = list(map(int, input().split()))
	inB = [False] * 1024
	for i in range(m):
		inB[b[i]] = True
	dp = [[0 for j in range(1024)] for i in range(n+1)]
	dp[0][0] = 1
	for i in range(1, n+1):
		a = ls[i-1]
		for j in range(1024):
			dp[i][j] = (dp[i-1][j] + dp[i-1][j^a]) % mod
	ans = 0
	for i in range(1024):
		if not inB[i]:
			ans = (ans + dp[n][i]) % mod
	print("Case {}: {}".format(t, ans))
