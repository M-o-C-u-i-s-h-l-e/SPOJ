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

	string str;
	while (cin >> str) {
		int n = str.size();
		if (n == 1 && str[0] == '0')
			break;
		vector<long long> dp(n);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			int temp = (str[i-1] - '0') * 10 + (str[i] - '0');
			dp[i] = (str[i] - '0') ? dp[i-1] : 0;
			if (temp > 9 && temp < 27)
				dp[i] += (i == 1) ? 1 : dp[i-2];
		}
		cout << dp[n-1] << endl;
	}
}
