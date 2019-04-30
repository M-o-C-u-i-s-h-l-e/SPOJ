# will get TLE

import bisect as bs

while True:
	n, ans = int(input()), 0
	if n == 0:
		break
	ls = sorted(list(map(int, input().split())))
	for i in range(n-2):
		for j in range(i+1, n-1):
			ans += n - bs.bisect_right(ls, ls[i]+ls[j])
	print(ans)
