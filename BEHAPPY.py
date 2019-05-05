# iterative approach

m, n = map(int, input().split())
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



# recursive approach

def solve(i, rem):
	if dp[i][rem] != -1:
		return dp[i][rem]
	if i == m:
		return 1 if rem == 0 else 0
	x = 0
	for j in range(ls[i][0], ls[i][1] + 1):
		if j > rem:
			break
		x += solve(i+1, rem-j)
	dp[i][rem] = x
	return x

m, n = map(int, input().split())
ls = [list(map(int, input().split())) for i in range(m)]
dp = [[-1 for j in range(2501)] for i in range(21)]
solve(0, n)
print(dp[0][n])
