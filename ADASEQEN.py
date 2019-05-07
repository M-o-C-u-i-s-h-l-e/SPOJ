# will get TLE

n, m = map(int, input().split())
ls = list(map(int, input().split()))
s1 = input()
s2 = input()
dp = [[0 for j in range(m+1)] for i in range(n+1)]
for i in range(1, n+1):
	for j in range(1, m+1):
		if s1[i-1] == s2[j-1]:
			dp[i][j] = dp[i-1][j-1] + ls[ord(s1[i-1]) - ord('a')]
		else:
			dp[i][j] = max(dp[i][j-1], dp[i-1][j])
print(dp[n][m])
