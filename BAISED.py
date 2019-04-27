for _ in range(int(input())):
	input()
	n = int(input())
	ls = list()
	for __ in range(n):
		st, x = map(str, input().split())
		ls.append(int(x))
	ls.sort()
	sum = 0
	for i in range(n):
		sum += abs((i+1) - ls[i])
	print(sum)
