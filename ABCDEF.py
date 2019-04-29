# will get TLE

from collections import defaultdict

n, count = int(input()), 0
ls = [int(input()) for i in range(n)]
abc = []
efd = []
for i in ls:
	for j in ls:
		for k in ls:
			abc.append(i * j + k)
			efd.append((i + j) * k)
d = defaultdict(int)
for i in efd:
	d[i] += 1
for i in abc:
	count += d[i]
print(count)
