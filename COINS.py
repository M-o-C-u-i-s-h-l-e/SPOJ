def solve(n):
	if n < 12:
		return n
	if n in dp.keys():
		return dp[n]
	dp[n] = max(n, solve(n//2) + solve(n//3) + solve(n//4))
	return dp[n]

while True:
	try:
		n = int(input())
	except:
		break
	dp = {}
	print(solve(n))
