# correct logic but won't work

while True:
	n = int(input())
	if n == 0:
		break
	inSign = [input() for _ in range(n)]
	while True:
		temp = input()
		if temp == "LAST CASE":
			break;
		temp = list(temp.split())
		acro = temp[0]
		temp.pop(0)
		words = []
		for i in temp:
			if i not in inSign:
				words.append(i)
		dp = [[0 for j in range(151)] for i in range(151)]
		dp[0][0] = 1
		dp2 = [[0 for j in range(151)] for i in range(151)]
		for i in range(len(words)):
			for j in range(len(acro)):
				mx = min(len(acro) - j, len(words[i]))
				for k in range(len(words[i])+1):
					dp2[k][0] = 1
				for k in range(1, mx+1):
					dp2[0][k] = 0
				for k in range(len(words[i])):
					for m in range(mx):
						dp2[k+1][m+1] = dp2[k][m+1]
						if words[i][k] == (acro[j+m]).lower():
							dp2[k+1][m+1] += dp2[k][m]
				for k in range(1, mx+1):
					dp[i+1][j+k] += dp[i][j] * dp2[len(words[i])][k]
		if dp[len(words)][len(acro)] == 0:
			print("{} is not a valid abbrevation".format(acro))
		else:
			print("{} can be formed in {} ways".format(acro, dp[len(words)][len(acro)]))
