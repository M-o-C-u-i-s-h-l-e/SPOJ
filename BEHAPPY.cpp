#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	while (cin >> m >> n) {
		if (n == 0 && m == 0)
			break;
		int dp[m+1][n+1];
		for (int i = 0; i <= n; i++)
			dp[0][i] = 0;
		dp[0][0] = 1;
		for (int i = 1, a, b; i <= m; i++) {
			cin >> a >> b;
			for (int j = 0; j <= n; j++) {
				dp[i][j] = 0;
				for (int k = a; k <= b && k <= j; k++)
					dp[i][j] += dp[i-1][j-k];
			}
		}
		cout << dp[m][n] << endl;
	}
}
