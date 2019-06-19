#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int oCost[n+1], cost[n+1][m+1], rating[n+1][m+1];
		int dp[n+1][m+1][k+1];
		for (int i = 1; i <= n; i++)
			cin >> oCost[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> cost[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> rating[i][j];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int l = 0; l <= k; l++) {
					if (j == 0) {
						if (i == 1) {
							dp[i][j][l] = 0;
						} else {
							dp[i][j][l] = dp[i-1][j][l];
							if (l >= oCost[i-1])
								dp[i][j][l] = max(dp[i][j][l], dp[i-1][m][l - oCost[i-1]]);
						}
					} else {
						dp[i][j][l] = dp[i][j-1][l];
						int x = 1;
						while (l >= x * cost[i][j]) {
							dp[i][j][l] = max(dp[i][j][l], x * rating[i][j] + dp[i][j-1][l - x * cost[i][j]]);
							x++;
						}
					}
				}
			}
		}
		int ans = 0;
		if (k >= oCost[n])
			ans = max(ans, dp[n][m][k - oCost[n]]);
		ans = max(ans, dp[n][0][k]);
		cout << ans << endl;
	}
}
