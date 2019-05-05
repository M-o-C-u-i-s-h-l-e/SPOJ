while True:
	m, n = map(int, input().split())
	if m == 0 and n == 0:
		break
	dp = [[0 for j in range(n+1)] for i in range(m+1)]
	for i in range(n+1):
		dp[0][i] = 0
	dp[0][0] = 1
	for i in range(1, m+1):
		a, b = map(int, input().split())
		for j in range(n+1):
			dp[i][j] = 0
			for k in range(a, b+1):
				if k > j:
					break
				dp[i][j] += dp[i-1][j-k]
	print(dp[m][n])
