#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

string s1, s2;
int k;

int solve(map<tuple<int, int, int>, int> &m, int i, int j, int k) {
	if (k == 0)
		return 0;
	if (i == -1 || j == -1)
		return -1;
	if (m.count({i, j, k}))
		return m[{i, j, k}];
	int first = -1;
	if (s1[i] == s2[j]) {
		first = solve(m, i-1, j-1, k-1);
		if (first != -1)
			first += s1[i];
	}
	int sec = solve(m, i-1, j, k);
	int thd = solve(m, i, j-1, k);
	return m[{i, j, k}] = max(first, max(sec, thd));
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
		cin >> s1 >> s2 >> k;
		map<tuple<int, int, int>, int> m;
		int res = solve(m, s1.size()-1, s2.size()-1, k);
		(res == -1) ? cout << 0 << endl : cout << res << endl;
	}
}
