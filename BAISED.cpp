#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long mod = 1e9+7;

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
    	long long n, sum = 0;
    	string str;
    	cin >> n;
    	vector<long long> v(n);
    	for (int i = 0; i < n; i++)
    		cin >> str >> v[i];
    	sort(v.begin(), v.end());
    	for (int i = 0; i < n; i++)
    		sum += abs((i+1) - v[i]);
    	cout << sum << endl;
    }
}
