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
		int n, w;
		cin >> n >> w;
		vector<int> v(w+1), dp(w+1);
		for (int i = 1; i <= w; i++) {
			cin >> v[i];
			dp[i] = v[i];
		}
		for (int i = 2; i <= w; i++) {
			for (int j = 1; j < i; j++) {
				if (v[i-j] == -1 || dp[j] == -1)
					continue;
				if (dp[i] == -1)
					dp[i] = dp[j] + v[i-j];
				else
					dp[i] = min(dp[i], dp[j] + v[i-j]);
			}
		}
		cout << dp[w] << endl;
	}
}
