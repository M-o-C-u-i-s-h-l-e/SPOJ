#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long t;
int n, m;
vector<long> a, b, c, d;

bool check(long x) {
	long Count = 0, y = t - x;
	for (int i = 0; i < n; i++)
		Count += (x - a[i] >= 0) ? (x - a[i]) / b[i] + 1 : 0;
	for (int i = 0; i < m; i++)
		Count -= (y - c[i] >= 0) ? (y - c[i]) / d[i] + 1 : 0;
	return Count <= 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> t;
	cin >> n;
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	cin >> m;
	c.resize(m), d.resize(m);
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i];
	long l = 0, r = t, ans = 0;
	while (l < r) {
		long m = l + (r - l) / 2;
		if (check(m)) { 
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m;
		}
	}
	cout << ans << endl;
}
