#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> lis(vector<int> &v) {
    vector<int> res;
    for (int i = 0, n = v.size(); i < n; i++) {
        int pos = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
        if (pos == res.size()) {
            res.emplace_back(v[i]);
        } else {
            res[pos] = v[i];
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cin >> k;
        vector<int> ans = lis(v);
        (k > ans.size()) ? cout << -1 << endl : cout << ans[k - 1] << endl;
    }
}
