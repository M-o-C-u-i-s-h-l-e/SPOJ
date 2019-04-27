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
    	int n, Count = 0;
    	cin >> n;
    	vector<long> v;
    	for (int i = 0; i < n; i++) {
    		long x;
    		cin >> x;
    		if (x == 1)
    			Count++;
    		else
    			v.push_back(x);
    	}
    	sort(v.begin(), v.end());
    	for (int i = 0; i < Count; i++)
    		cout << 1 << " ";
    	if (v.size() == 2 && v[0] == 2 && v[1] == 3)
    		cout << "2 3\n";
    	else {
    		for (int i = v.size()-1; i >= 0; i--)
    			cout << v[i] << " ";
    		cout << endl;
    	}
    }
}
