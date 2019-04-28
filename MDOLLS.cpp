#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
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
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end(), comp);
		vector<int> lis(n);
		lis[0] = v[0].second;
		int pos = 1;
		for (int i = 1; i < n; i++) {
			if (v[i].second < lis[0])
				lis[0] = v[i].second;
			else if (v[i].second >= lis[pos])
				lis[++pos] = v[i].second;
			else {
				int j = upper_bound(lis.begin(), lis.begin() + pos, v[i].second) - lis.begin();
				lis[j] = v[i].second;
			}
		}
		cout << pos << endl;
	}
}
