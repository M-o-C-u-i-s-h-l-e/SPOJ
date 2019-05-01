def check(x):
	Count, y = 0, t - x;
	for i in range(n):
		Count += (x - a[i][0]) // a[i][1] + 1 if x - a[i][0] >= 0 else 0
	for i in range(m):
		Count -= (y - b[i][0]) // b[i][1] + 1 if y - b[i][0] >= 0 else 0
	return Count <= 0

t = int(input())
n = int(input())
a = [list(map(int, input().split())) for i in range(n)]
m = int(input())
b = [list(map(int, input().split())) for i in range(m)]
l, r, ans = 0, t, 0
while l < r:
	M = l + (r - l) // 2
	if check(M):
		ans = max(ans, M)
		l = M + 1
	else:
		r = M
print(ans)
