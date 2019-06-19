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

    int n;
    while (cin >> n) {
    	if (n == -1)
    		break;
    	vector<int> v(n), pre(n), org(n);
    	for (int i = 0; i < n; i++)
    		cin >> v[i];
    	int sum = accumulate(v.begin(), v.end(), 0);
    	if (sum % n != 0) {
    		cout << -1 << endl;
    		continue;
    	}
    	pre[0] = v[0];
    	int avg = sum / n;
    	org[0] = avg;
    	for (int i = 1; i < n; i++)
    		pre[i] = pre[i-1] + v[i], org[i] = org[i-1] + avg;
    	int Max = INT_MIN;
    	for (int i = 0; i < n; i++)
    		Max = max(Max, abs(pre[i] - org[i]));
    	cout << Max << endl;
    }
}
