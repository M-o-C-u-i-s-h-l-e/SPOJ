# will get TLE

def solve(dec, inc, id):
	if dp[dec][inc][id] != -1:
		return dp[dec][inc][id]
	if id == n:
		return 0
	if arr[id] < arr[dec]:
		dp[dec][inc][id] = solve(id, inc, id+1)
	if arr[id] > arr[inc]:
		if dp[dec][inc][id] == -1:
			dp[dec][inc][id] = solve(dec, id, id+1)
		else:
			dp[dec][inc][id] = min(solve(dec, id, id+1), dp[dec][inc][id])
	if dp[dec][inc][id] == -1:
		dp[dec][inc][id] = 1 + solve(dec, inc, id+1)
	else:
		dp[dec][inc][id] = min(1 + solve(dec, inc, id+1), dp[dec][inc][id])
	return dp[dec][inc][id]

while True:
	n = int(input())
	if n == -1:
		break
	arr = list(map(int, input().split()))
	arr = arr + ([0] * (200 - len(arr))) + [int(1e7)] + [int(-1e7)]
	dp = [[[-1 for k in range(202)] for j in range(202)] for i in range(202)]
	print(solve(200, 201, 0))
