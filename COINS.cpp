#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long solve(long long n, long long dp[]) {
	if (n < 12)
		return n;
	if (dp[n])
		return dp[n];
	return dp[n] = max(n, solve(n/2, dp) + solve(n/3, dp) + solve(n/4, dp));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long n;
	while (cin >> n) {
		long long *dp = new long long[n+1];
		cout << solve(n, dp) << endl;
	}
}
