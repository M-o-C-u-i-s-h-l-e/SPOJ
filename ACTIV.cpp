#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long mod = 1e8;
int n;
vector<pair<int, int>> arr;

void solve() {
	int dp[n][2];
	vector<int> v;
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	v.push_back(arr[0].first);
	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
		if (arr[i].second < v[0]) {
			dp[i][1] = 1;
		} else {
			int pos = upper_bound(v.begin(), v.end(), arr[i].second) - v.begin();
			pos--;
			dp[i][1] = (1 + dp[pos][0] + dp[pos][1]) % mod;
		}
		v.push_back(arr[i].first);
	}
	printf("%0.8d\n", (dp[n-1][0] + dp[n-1][1]) % mod);
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
		if (n == -1)
			break;
		arr.resize(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].second >> arr[i].first;
		sort(arr.begin(), arr.end());
		solve();
	}
}
