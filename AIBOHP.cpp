#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string s1, s2;
int dp[7007][7007];

int lcs() {
	for (int i = 0; i <= s1.size(); i++)
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	return dp[s1.size()][s2.size()];
}

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
		string str;
		cin >> str;
		s1 = s2 = str;
		reverse(s2.begin(), s2.end());
		cout << str.size() - lcs() << endl;
	}
}
