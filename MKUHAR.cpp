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

	int N, M;
	cin >> N >> M;
	int x[N], y[N], ss[N], sp[N], ls[N], lp[N];
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i] >> ss[i] >> sp[i] >> ls[i] >> lp[i];
	int l = 0, r = M, ans = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;
		int total = 0;
		for (int i = 0; i < N; i++) {
			int req = x[i] * m - y[i];
			int best = 99999999;
			int lim = int(ceil(req / double(ss[i])));
			for (int j = 0; j <= lim; j++) {
				int pur = j * ss[i];
				int rem = (req >= pur) ? int(ceil((req-pur)/double(ls[i]))) : 0;
				best = min(best, j * sp[i] + rem * lp[i]);
			}
			if (best > M || total + best > M) {
				total = M + 1;
				break;
			} else {
				total += best;
			}
		}
		if (total <= M) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << ans << endl;
}
