#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
int v1[17], v2[17];
int dp[(1<<17)-1];

int solve(int state, int curRow) {
	if (curRow == n)
		return 0;
	if (dp[state] != -1)
		return dp[state];
	int Min = INT_MAX;
	for (int i = 0; i < n; i++)
		if (!(state & (1 << i)))
			Min = min(Min, abs(curRow-i) + abs(v1[curRow] - v2[i]) + solve(state | (1 << i), curRow + 1));
	return dp[state] = Min;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		if (n == 0)
			break;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			cin >> v1[i];
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		cout << solve(0, 0) << endl;
	}
}
