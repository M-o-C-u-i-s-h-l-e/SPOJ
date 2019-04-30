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
		string s1, s2;
		cin >> s1 >> s2;
		map<char, int> m1, m2;
		for (int i = 0; i < s1.size(); i++)
			m1[s1[i]]++;
		for (int i = 0; i < s2.size(); i++)
			m2[s2[i]]++;
		int ans = INT_MAX;
		for (auto itr = m1.begin(); itr != m1.end(); itr++) {
			char c = itr->first;
			int val = itr->second;
			ans = min(ans, m2[c] / val);
		}
		cout << ans << endl;
	}
}
