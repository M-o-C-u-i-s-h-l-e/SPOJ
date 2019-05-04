#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, sol;
int arr[202], dp[202][202][202];

int solve(int dec, int inc, int id) {
	if (dp[dec][inc][id] != -1)
		return dp[dec][inc][id];
	if (id == n)
		return 0;
	if (arr[id] < arr[dec])
		dp[dec][inc][id] = solve(id, inc, id+1);
	if (arr[id] > arr[inc]) {
		if (dp[dec][inc][id] == -1)
			dp[dec][inc][id] = solve(dec, id, id+1);
		else
			dp[dec][inc][id] = min(solve(dec, id, id+1), dp[dec][inc][id]);
	}
	if (dp[dec][inc][id] == -1)
		dp[dec][inc][id] = 1 + solve(dec, inc, id+1);
	else
		dp[dec][inc][id] = min(1 + solve(dec, inc, id+1), dp[dec][inc][id]);
	return dp[dec][inc][id];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	arr[200] = 1e7;
	arr[201] = -1e7;
	while (cin >> n) {
		if (n == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		memset(dp, -1, sizeof(dp));
		sol = solve(200, 201, 0);
		cout << sol << endl;
	}
}
