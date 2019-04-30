#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define F first
#define S second

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
		int n;
		cin >> n;
		vector<pair<pair<int, int>, int>> v(n);
		vector<int> s(n), d(n), c(n), dp(n+1, 0);
		for (int i = 0; i < n; i++)
			cin >> v[i].F.F >> v[i].F.S >> v[i].S;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
			s[i] = v[i].F.F, d[i] = v[i].F.S, c[i] = v[i].S;
		for (int i = n-1; i >= 0; i--)
			dp[i] = max(dp[i+1], c[i] + dp[(upper_bound(s.begin(), s.end(), s[i]+d[i]) - s.begin())]);
		cout << dp[0] << endl;
	}
}
