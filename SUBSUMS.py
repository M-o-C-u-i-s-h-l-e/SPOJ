# will get TLE

import bisect as bs

def generateSubs(start, n, ls, arr):
	Sum = 0
	for i in range(1 << n):
		Sum = 0
		for j in range(n):
			if i & (1 << j):
				Sum += ls[j + start]
		arr.append(Sum)

n, a, b = map(int, input().split())
ls = [int(input()) for i in range(n)]
l = []
r = []
generateSubs(0, n//2, ls, l)
generateSubs(n//2, n//2+1 if n&1 else n//2, ls, r)
r.sort()
ans = 0
for i in l:
	ans += bs.bisect_right(r, b-i) - bs.bisect_left(r, a-i)
print(ans)
