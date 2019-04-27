N = 1007
arr = [[0] * N for i in range(N)]
Count = [[0] * N for i in range(N)]

while True:
	k = int(input())
	if k == 0:
		break
	s1 = input()
	s2 = input()
	for i in range(1, len(s1)+1):
		for j in range(1, len(s2)+1):
			arr[i][j] = max(arr[i-1][j], arr[i][j-1])
			if s1[i-1] == s2[j-1]:
				Count[i][j] = Count[i-1][j-1] + 1
			else:
				Count[i][j] = 0
			if Count[i][j] >= k:
				for z in range(k, Count[i][j]+1):
					arr[i][j] = max(arr[i][j], arr[i-z][j-z] + z)
	print(arr[len(s1)][len(s2)])
