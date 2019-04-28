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
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end());
		vector<pair<int, int>> lis;
		lis.push_back({v[n-1].first, v[n-1].second});
		for (int i = n-2; i >= 0; i--) {
			int l = 0, r = lis.size()-1;
			while (l <= r) {
				int m = (l + r) / 2;
				(lis[m].first < v[i].first || lis[m].second < v[i].second) ? l = m+1 : r = m-1;
			}
			if (l == lis.size())
				lis.push_back({v[i].first, v[i].second});
			else
				lis[l].first = v[i].first, lis[l].second = v[i].second;
		}
		cout << lis.size() << endl;
	}
}
