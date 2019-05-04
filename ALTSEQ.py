# will get TLE

n = int(input())
ls = list(map(int, input().split()))
dp = [0] * n
sign = [True if ls[i] > 0 else False for i in range(n)]
for i in range(n):
	for j in range(i):
		if sign[i] != sign[j] and abs(ls[i]) > abs(ls[j]):
			dp[i] = max(dp[i], dp[j] + 1)
	if dp[i] == 0:
		dp[i] = 1
print(max(dp))
