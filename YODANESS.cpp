#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void update(vector<int> &BITree, int pos, int val, int n) {
	while (pos <= n) {
		BITree[pos] += val;
		pos += (pos & -pos);
	}
}

int query(vector<int> &BITree, int pos) {
	int sum = 0;
	while (pos) {
		sum += BITree[pos];
		pos -= (pos & -pos);
	}
	return sum;
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
		vector<string> arr(n);
		map<string, int> m;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			m[str] = i + 1;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			v[i] = m[arr[i]];
		vector<int> BITree(n+1, 0);
		for (int i = n-1; i >= 0; i--) {
			Count += query(BITree, v[i]);
			update(BITree, v[i], 1, n);
		}
		cout << Count << endl;
	}
}
