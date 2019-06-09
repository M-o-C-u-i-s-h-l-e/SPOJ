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

	int n;
	cin >> n;
	vector<int> v(n), dp(n, 0);
	vector<bool> sign(n, true);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 0)
			sign[i] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (sign[i] != sign[j] && abs(v[i]) > abs(v[j]))
				dp[i] = max(dp[i], dp[j]+1);
		if (dp[i] == 0)
			dp[i] = 1;
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}
