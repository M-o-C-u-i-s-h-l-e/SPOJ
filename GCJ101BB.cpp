#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
    	long long n, k, b, t, Count = 0, fail = 0, sum = 0;
    	cin >> n >> k >> b >> t;
    	vector<long long> p(n), s(n);
    	for (int i = 0; i < n; i++)
    		cin >> p[i];
    	for (int i = 0; i < n; i++)
    		cin >> s[i];
    	for (int i = n-1; i >= 0 && Count < k; i--)
    		(b <= s[i] * t + p[i]) ? Count++, sum += fail : fail++;
    	cout << "Case #" << tt << ": ";
    	(Count == k) ? cout << sum << endl : cout << "IMPOSSIBLE\n";
    }
}
