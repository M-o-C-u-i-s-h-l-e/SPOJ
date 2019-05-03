# will get TLE

def bits(n):
	Count = 0
	while n:
		Count += n & 1
		n >>= 1
	return Count

for _ in range(int(input())):
	n = int(input())
	ls = [list(map(int, input().split())) for i in range(n)]
	dp = [0] * (1 << n)
	dp[0] = 1
	Max = 1 << n
	for i in range(Max):
		temp = bits(i)
		if temp < n:
			for j in range(n):
				if ls[temp][j] and (i & (1 << j)) == 0:
					dp[i | (1 << j)] += dp[i]
	print(dp[Max-1])
