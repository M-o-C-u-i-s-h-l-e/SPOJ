#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

vector<int> BITree;

inline void update(int pos, int val, int n) {
	while (pos <= n) {
		BITree[pos] = min(BITree[pos], val);
		pos += (pos & -pos);
	}
}

inline int query(int pos) {
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
	
	int n, Count = 0;
	scanf("%d", &n);
	vector<pair<int, pair<int, int>>> v(n);
	BITree.resize(n + 7, INT_MAX);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i].S.S);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i].S.F);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i].F);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (query(v[i].S.F) > v[i].S.S)
			Count++;
		update(v[i].S.F, v[i].S.S, n + 7);
	}
	printf("%d\n", Count);
}
