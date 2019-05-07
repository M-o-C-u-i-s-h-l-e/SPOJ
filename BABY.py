# will get TLE

def solve(state, curRow):
	if curRow == n:
		return 0
	if dp[state] != -1:
		return dp[state]
	Min = 1e9
	for i in range(n):
		if not (state & (1 << i)):
			Min = min(Min, abs(curRow -i) + abs(ls1[curRow] - ls2[i]) + solve(state | (1 << i), curRow + 1))
	dp[state] = Min
	return Min

while True:
	n = int(input())
	if n == 0:
		break
	ls1 = list(map(int, input().split()))
	ls2 = list(map(int, input().split()))
	dp = [-1] * ((1 << (n+1)) - 1)
	print(solve(0, 0))
