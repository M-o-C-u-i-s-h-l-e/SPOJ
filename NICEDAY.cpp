#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

vector<int> BITree(1e5+7);

void update(int pos, int val, int n) {
	while (pos <= n) {
		BITree[pos] = min(BITree[pos], val);
		pos += (pos & -pos);
	}
}

int query(int pos) {
	int Min = INT_MAX;
	while (pos) {
		Min = min(BITree[pos], Min);
		pos -= (pos & -pos);
	}
	return Min;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, Count = 0;
		cin >> n;
		vector<pair<int, pair<int, int>>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].F >> v[i].S.F >> v[i].S.S;
		sort(v.begin(), v.end());
		fill(BITree.begin(), BITree.begin() + (n + 7), INT_MAX);
		for (int i = 0; i < n; i++) {
			if (query(v[i].S.F) > v[i].S.S)
				Count++;
			update(v[i].S.F, v[i].S.S, n + 7);
		}
		cout << Count << endl;
	}
}
