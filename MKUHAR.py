# will get TLE

from math import ceil

N, M = map(int, input().split())
x = [0] * N
y = [0] * N
ss = [0] * N
sp = [0] * N
ls = [0] * N
lp = [0] * N
for i in range(N):
	temp = list(map(int, input().split()))
	x[i], y[i], ss[i], sp[i], ls[i], lp[i] = temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]
l, r, ans = 0, M, 0
while l <= r:
	m = l + (r - l) // 2
	total = 0
	for i in range(N):
		req = x[i] * m - y[i]
		best = 99999999
		lim = int(ceil(req / ss[i]))
		for j in range(lim+1):
			pur = j * ss[i]
			rem = 0
			if req >= pur:
				rem += int(ceil((req-pur)/ls[i]))
			best = min(best, j * sp[i] + rem * lp[i])
		if best > M or best + total > M:
			total = M + 1
			break
		else:
			total += best
	if total <= M:
		ans = max(ans, m)
		l = m + 1
	else:
		r = m - 1
print(ans)
