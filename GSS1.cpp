#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class node {
public:
	int all, Pre, Suf, Max;
	node() {
		all = -(1e6+7), Pre = -(1e6+7), Suf = -(1e6+7), Max = -(1e6+7);
	}
};

node null;

int nextPowerOf2(int n) {
	int x = 1;
	while (x < n)
		x <<= 1;
	return x;
}

node merge(node n1, node n2) {
	node temp;
	temp.Max = max(max(n1.Max, n2.Max), n1.Suf + n2.Pre);
	temp.Pre = max(n1.Pre, n1.all + n2.Pre);
	temp.Suf = max(n2.Suf, n2.all + n1.Suf);
	temp.all = n1.all + n2.all;
	return temp;
}

void constructSegTree(vector<node> &segTree, vector<int> &input, int low, int high, int pos) {
	if (low == high) {
		segTree[pos].Max = input[low];
		segTree[pos].Pre = input[low];
		segTree[pos].Suf = input[low];
		segTree[pos].all = input[low];
		return;
	}
	int mid = (low + high) >> 1;
	constructSegTree(segTree, input, low, mid, 2 * pos + 1);
	constructSegTree(segTree, input, mid + 1, high, 2 * pos + 2);
	segTree[pos] = merge(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

vector<node> createSegTree(vector<int> &input) {
	int n = nextPowerOf2(input.size());
	vector<node> segTree(n << 1);
	constructSegTree(segTree, input, 0, input.size() - 1, 0);
	return segTree;
}

node query(vector<node> &segTree, int low, int high, int qLow, int qHigh, int pos) {
	if (low >= qLow && high <= qHigh)
		return segTree[pos];
	if (low > qHigh || high < qLow)
		return null;
	int mid = (low + high) >> 1;
	node n1 = query(segTree, low, mid, qLow, qHigh, 2 * pos + 1);
	node n2 = query(segTree, mid + 1, high, qLow, qHigh, 2 * pos + 2);
	return merge(n1, n2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<node> segTree = createSegTree(v);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node ans = query(segTree, 0, n - 1, l - 1, r - 1, 0);
		cout << ans.Max << endl;
	}
}
