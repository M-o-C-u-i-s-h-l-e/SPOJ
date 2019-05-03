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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		vector<long long> dp(1 << n, 0);
		dp[0] = 1;
		long long Max = 1 << n;
		for (long long i = 0; i < Max; i++) {
			int temp = __builtin_popcount(i);
			for (int j = 0; j < n; j++)
				if (arr[temp][j] && (i & (1 << j)) == 0)
					dp[i | (1 << j)] += dp[i];
		}
		cout << dp[Max-1] << endl;
	}
}
