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

	long long n, ans = 0;
	cin >> n;
	vector<long long> v(n), arr;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		if (v[i])
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					arr.push_back(v[i] * (v[j] + v[k]));
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				long long x = v[i] * v[j] + v[k];
				ans += (upper_bound(arr.begin(), arr.end(), x) - lower_bound(arr.begin(), arr.end(), x));
			}
	cout << ans << endl;
}
