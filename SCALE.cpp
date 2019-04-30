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

	long long n, x;
	cin >> n >> x;
	if (2 * x > pow(3, n) - 1)
		cout << -1 << endl;
	else {
		vector<int> v;
		while (x) {
			v.push_back(x % 3);
			x /= 3;
		}
		v.push_back(0);
		for (int i = 0; i < v.size()-1; i++) {
			if (v[i] == 2)
				v[i+1]++, v[i] = -1;
			else if (v[i] == 3)
				v[i+1]++, v[i] = 0;
		}
		for (int i = 0; i < v.size(); i++)
			if (v[i] == -1)
				cout << i + 1 << " ";
		cout << endl;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == 1)
				cout << i + 1 << " ";
		cout << endl;
	}
}
