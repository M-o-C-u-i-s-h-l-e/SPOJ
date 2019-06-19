#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	bitset<100001> bs;
	bs[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		bs |= bs << v[i];
	}
	int ans[100007] = {0};
	for (int i = 1; i <= 100001; i++)
		ans[i] = ans[i-1] + bs[i];
	while (q--) {
		int s, e;
		cin >> s >> e;
		cout << ans[e] - ans[s-1] << endl;
	}
}
