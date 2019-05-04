  import bisect as bs

def lbs():
	if n == 0:
		return 0
	inc = [0] * n
	tail1 = [0] * n
	dec = [0] * n
	tail2 = [0] * n
	inc[0] = ls[0]
	id = 1
	tail1[0] = 0
	for i in range(1, n):
		if ls[i] < inc[0]:
			inc[0] = ls[i]
			tail1[i] = 0
		elif ls[i] > inc[id-1]:
			inc[id] = ls[i]
			tail1[i] = id
			id += 1
		else:
			pos = bs.bisect_left(inc, ls[i], 0, id)
			inc[pos] = ls[i]
			tail1[i] = pos
	id = 1
	ls.reverse()
	dec[0] = ls[0]
	tail2[0] = 0
	for i in range(1, n):
		if ls[i] < dec[0]:
			dec[0] = ls[i]
			tail2[i] = 0
		elif ls[i] > dec[id-1]:
			dec[id] = ls[i]
			tail2[i] = id
			id += 1
		else:
			pos = bs.bisect_left(dec, ls[i], 0, id)
			dec[pos] = ls[i]
			tail2[i] = pos
	tail2.reverse()
	ans = 0
	for i in range(n):
		if ans < tail1[i] + tail2[i] + 1:
			ans = tail1[i] + tail2[i] + 1
	return ans

for _ in range(int(input())):
	n = int(input())
	ls = list(map(int, input().split()))
	print(lbs())
