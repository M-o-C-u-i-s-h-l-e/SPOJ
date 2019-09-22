#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 10000001

vector<long> bit(MAX);

long get(int idx) {
	long res = 0;
	while (idx) {
		res += bit[idx];
		idx -= (idx & -idx);
	}
	return res;
}

void update(int idx, int val) {
	while (idx < MAX) {
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long n, ans = 0;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i + 1;
		}
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		fill(bit.begin(), bit.end(), 0);
		for (int i = 0; i < n; i++) {
			ans += get(v[i].second - 1);
			update(v[i].second, 1);
		}
		cout << ans << endl;
	}
}
