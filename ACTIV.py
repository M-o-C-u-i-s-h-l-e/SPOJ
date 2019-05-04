# will get TLE

import bisect as bs
mod = int(1e8)

def solve():
	dp = [[0, 0] for i in range(n)]
	ls = list()
	dp[0][1] = 1
	ls.append(arr[0][0])
	for i in range(1, n):
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod
		if arr[i][1] < ls[0]:
			dp[i][1] = 1
		else:
			pos = bs.bisect_right(ls, arr[i][1])
			pos -= 1
			dp[i][1] = (1 + dp[pos][0] + dp[pos][1]) % mod
		ls.append(arr[i][0])
	res = (dp[n-1][0] + dp[n-1][1]) % mod
	ans = ('0' * (8 - len(str(res)))) + str(res)
	print(ans)

while True:
	n = int(input())
	if n == -1:
		break
	arr = [list(map(int, input().split())) for i in range(n)]
	for i in range(n):
		arr[i][0], arr[i][1] = arr[i][1], arr[i][0]
	arr.sort()
	solve()	
