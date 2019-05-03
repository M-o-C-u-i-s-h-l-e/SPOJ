while True:
	st = input()
	n = len(st)
	if n == 1 and st[0] == '0':
		break
	dp = [0] * n
	dp[0] = 1
	for i in range(1, n):
		temp = int(st[i-1]) * 10 + int(st[i])
		dp[i] = dp[i-1] if st[i] != '0' else 0
		if temp > 9 and temp < 27:
			dp[i] += 1 if i == 1 else dp[i-2]
	print(dp[n-1])
