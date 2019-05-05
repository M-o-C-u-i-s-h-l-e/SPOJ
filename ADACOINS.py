# will get TLE

n, q = map(int, input().split())
ls = list(map(int, input().split()))
bit = 1
for i in ls:
	bit |= bit << i
st = format(bit, "0100001b")
st = st[::-1]
ans = [0] * 100001
for i in range(1, 100001):
	ans[i] = ans[i-1] + (1 if st[i] == '1' else 0)
for _ in range(q):
	s, e = map(int, input().split())
	print(ans[e] - ans[s-1])
