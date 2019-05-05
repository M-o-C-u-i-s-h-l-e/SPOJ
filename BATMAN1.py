# will get TLE
# will also get runtime erroe (NZEC), due to input format

for _ in range(int(input())):
	n, m, k = map(int, input().split())
	oCost = [0] + list(map(int, input().split()))
	cost = [0] + [[0] + list(map(int, input().split())) for i in range(n)]
	rating = [0] + [[0] + list(map(int, input().split())) for i in range(n)]
	dp = [[[0 for l in range(k+1)] for j in range(m+1)] for i in range(n+1)]
	for i in range(1, n+1):
		for j in range(m+1):
			for l in range(k+1):
				if j == 0:
					if i == 1:
						dp[i][j][l] = 0
					else:
						dp[i][j][l] = dp[i-1][j][l];
						if l >= oCost[i-1]:
							dp[i][j][l] = max(dp[i][j][l], dp[i-1][m][l - oCost[i-1]])
				else:
					dp[i][j][l] = dp[i][j-1][l]
					x = 1
					while l >= x * cost[i][j]:
						dp[i][j][l] = max(dp[i][j][l], x * rating[i][j] + dp[i][j-1][l - x * cost[i][j]])
						x += 1
	ans = 0
	if k >= oCost[n]:
		ans = max(ans, dp[n][m][k - oCost[n]])
	ans = max(ans, dp[n][0][k])
	print(ans)
