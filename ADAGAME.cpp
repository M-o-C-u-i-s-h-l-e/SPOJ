#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
string dp[10001][101];

string minMax(string str, int t) {
	if (t > n)
		return str;
	int no = stoi(str);
	if (dp[no][t] != "")
		return dp[no][t];
	string ans = (t & 1) ? "0000" : "9999";
	for (int i = 0; i < 4; i++) {
		string temp = str;
		(temp[i] == '9') ? temp[i] = '0' : temp[i]++;
		if (t & 1)
			ans = max(ans, minMax(temp, t+1));
		else
			ans = min(ans, minMax(temp, t+1));
	}
	return dp[no][t] = ans;
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
		for (int i = 0; i < 10001; i++)
			for (int j = 0; j < 101; j++)
				dp[i][j] = "";
		string str;
		cin >> str >> n;
		string res = minMax(str, 1);
		(res > str) ? cout << "Ada\n" : cout << "Vinit\n";
	}
}
