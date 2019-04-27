#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> m(n), w(n);
    	for (int i = 0; i < n; i++)
    		cin >> m[i];
    	for (int i = 0; i < n; i++)
    		cin >> w[i];
    	sort(m.begin(), m.end());
    	sort(w.begin(), w.end());
    	long long sum = 0;
    	for (int i = 0; i < n; i++)
    		sum += m[i] * w[i];
    	cout << sum << endl;
    }
}
