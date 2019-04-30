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

	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		int ans = 0;
		vector<long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 0; i < n-2; i++)
			for (int j = i+1; j < n-1; j++)
				ans += v.end() - upper_bound(v.begin(), v.end(), v[i]+v[j]);
		cout << ans << endl;
	}
}
