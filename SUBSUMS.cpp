#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void generateSubs(int start, int n, vector<long long> v, vector<long long> &arr) {
	long long sum;
	for (long long i = 1; i < (1 << n); i++) {
		sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += v[j + start];
		arr.emplace_back(sum);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long n, a, b, ans = 0;
	cin >> n >> a >> b;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<long long> l, r;
	generateSubs(0, n/2, v, l);
	generateSubs(n/2, (n&1) ? n/2+1 : n/2, v, r);
	sort(r.begin(), r.end());
	for (int i = 0; i < l.size(); i++) {
		int L = lower_bound(r.begin(), r.end(), a-l[i]) - r.begin();
		int R = upper_bound(r.begin(), r.end(), b-l[i]) - r.begin();
		ans += R - L;
	}
	cout << ans << endl;
}
