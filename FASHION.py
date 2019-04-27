for _ in range(int(input())):
	n = int(input())
	m = sorted(list(map(int, input().split())))
	w = sorted(list(map(int, input().split())))
	ls = [m[i] * w[i] for i in range(n)]
	print(sum(ls))
