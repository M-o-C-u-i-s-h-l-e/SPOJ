#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<int> v;

int lbs() {
	if (n == 0)
		return 0;
	vector<int> inc(n), tail1(n);
	vector<int> dec(n), tail2(n);
	inc[0] = v[0];
	int id = 1;
	tail1[0] = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < inc[0]) {
			inc[0] = v[i];
			tail1[i] = 0;
		} else if (v[i] > inc[id-1]) {
			inc[id++] = v[i];
			tail1[i] = id - 1;
		} else {
			int pos = lower_bound(inc.begin(), inc.begin()+id, v[i]) - inc.begin();
			inc[pos] = v[i];
			tail1[i] = pos;
		}
	}
	id = 1;
	reverse(v.begin(), v.end());
	dec[0] = v[0];
	tail2[0] = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < dec[0]) {
			dec[0] = v[i];
			tail2[i] = 0;
		} else if (v[i] > dec[id-1]) {
			dec[id++] = v[i];
			tail2[i] = id - 1;
		} else {
			int pos = lower_bound(dec.begin(), dec.begin()+id, v[i]) - dec.begin();
			dec[pos] = v[i];
			tail2[i] = pos;
		}
	}
	reverse(tail2.begin(), tail2.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (ans < tail1[i] + tail2[i] + 1)
			ans = tail1[i] + tail2[i] + 1;
	return ans;
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
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << lbs() << endl;
	}
}
