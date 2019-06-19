#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long mod = 1e8+7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n), b(m);
		vector<bool> inB(1024, false);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			inB[b[i]] = true;
		}
		int dp[n+1][1024];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int a = v[i-1];
			for (int j = 0; j < 1024; j++)
				dp[i][j] = (dp[i-1][j] + dp[i-1][j^a]) % mod;
		}
		int ans = 0;
		for (int i = 0; i < 1024; i++)
			if (!inB[i])
				ans = (ans + dp[n][i]) % mod;
		cout << "Case " << t << ": " << ans << endl;
	}
}
