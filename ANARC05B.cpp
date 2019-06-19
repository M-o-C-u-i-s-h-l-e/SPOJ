#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long __bsearch(vector<long long> v, long long key) {
	long long l = 0, r = v.size() - 1;
	while (l <= r) {
		long long m = l + (r - l) / 2;
		if (v[m] == key)
			return m;
		(v[m] < key) ? l = m + 1 : r = m - 1;
	}
	return -1;
}

long long Sum(vector<long long> v, long long s, long long e) {
	long long res = 0;
	for (long long i = s; i <= e; i++)
		res += v[i];
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long n, m, a1, a2, b1, b2, s1, s2;
	while (cin >> n) {
		if (n == 0)
			break;
		vector<long long> a(n);
		for (long long i = 0; i < n; i++)
			cin >> a[i];
		cin >> m;
		vector<long long> b(m);
		for (long long i = 0; i < m; i++)
			cin >> b[i];
		vector<long long> v;
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(v, v.begin()));
		long long ans = 0;
		if (v.size() == 0) {
			s1 = Sum(a, 0, n-1);
			s2 = Sum(b, 0, m-1);
			ans = max(s1, s2);
			cout << ans << endl;
			continue;
		}
		a1 = __bsearch(a, v[0]), b1 = __bsearch(b, v[0]);
		s1 = Sum(a, 0, a1-1), s2 = Sum(b, 0, b1-1);
		ans = max(s1, s2);
		for (long long i = 1; i < v.size(); i++) {
			a1 = __bsearch(a, v[i-1]), a2 = __bsearch(a, v[i]);
			b1 = __bsearch(b, v[i-1]), b2 = __bsearch(b, v[i]);
			s1 = Sum(a, a1+1, a2-1) + v[i-1];
			s2 = Sum(b, b1+1, b2-1) + v[i-1];
			ans += max(s1, s2);
		}
		a1 = __bsearch(a, v[v.size()-1]), b1 = __bsearch(b, v[v.size()-1]);
		s1 = Sum(a, a1+1, n-1) + v[v.size()-1], s2 = Sum(b, b1+1, m-1) + v[v.size()-1];
		ans += max(s1, s2);
		cout << ans << endl;
	}
}
