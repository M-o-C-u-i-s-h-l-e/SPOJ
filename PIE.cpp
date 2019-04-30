#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, f;
vector<double> arr;

bool check(double x) {
	int total = 0;
	if (x == 0)	return false;
	for (int i = 0; i < n; i++)
		total += (int)(arr[i] / x);
	return total >= f;
}

double solve() {
	double l = 0, r = arr[n-1];
	while (r - l >= 1e-3) {
		double m = l + (r - l) / 2;
		(check(m)) ? l = m : r = m;
	}
	return l;
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
		cin >> n >> f;
		f++;
		vector<int> v(n);
		arr.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
			arr[i] = v[i] * v[i] * M_PI;
		printf("%.4f\n", solve());
	}
}
