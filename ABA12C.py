for _ in range(int(input())):
	n, k = map(int, input().split())
	ls = [(x, i) for i, x in enumerate(map(int, input().split()), 1) if x >= 0]
	dp = [0] + [9999] * k
	for v, i in ls:
		for j in range(i, k+1):
			if dp[j-1] != 9999:
				dp[j] = min(dp[j], dp[j-i] + v)
	print(dp[k]) if dp[k] != 9999 else print(-1)
