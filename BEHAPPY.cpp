// iterative approach

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

	int n, m;
	cin >> m >> n;
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



// recursive approach

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int m, n;
int a[21], b[21], dp[21][2501];

int solve(int i, int rem) {
	if (dp[i][rem] != -1)
		return dp[i][rem];
	if (i == m)
		return (rem == 0) ? 1 : 0;
	int x = 0;
	for (int j = a[i]; j <= b[i] && j <= rem; j++)
		x += solve(i+1, rem-j);
	return dp[i][rem] = x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	memset(dp, -1, sizeof(dp));
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i];
	solve(0, n);
	cout << dp[0][n] << endl;
}
