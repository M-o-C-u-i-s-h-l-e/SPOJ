#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int s1 = -1, s2 = -1;
        for (int i = n-1; i > 0; i--) {
            if (v[i] > v[i-1]) {
                s1 = i - 1;
                break;
            }
        }
        if (s1 != -1) {
            for (int i = n-1; i > s1; i--) {
                if (v[i] > v[s1]) {
                    s2 = i;
                    break;
                }
            }
            swap(v[s1], v[s2]);
            sort(v.begin() + (s1+1), v.end());
            for (int i = 0; i < n; i++)
                cout << v[i];
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
