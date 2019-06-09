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

	int N, M;
	map<char, int> m;
	string s1, s2;
	cin >> N >> M;
	for (char c = 'a'; c <= 'z'; c++)
		cin >> m[c];
	cin >> s1 >> s2;
	int dp[N+1][M+1];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + m[s1[i-1]];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[N][M] << endl;
}
