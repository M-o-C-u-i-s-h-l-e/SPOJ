#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        int cur = 1, i = 0;
        vector<int> v(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (i = 0; i < n; i++) {
            if (v[i] != 1)
                st.push(v[i]);
            else
                break;
        }
        for (cur = 1; cur < n; cur++) {
            if (v[i] == cur) {
                i++;
                continue;
            }
            if (!st.empty() && st.top() == cur) {
                st.pop();
                continue;
            }
            if (st.empty() || st.top() > v[i]) {
                st.push(v[i++]), cur--;
                continue;
            }
            break;
        }
        (cur == n) ? cout << "yes\n" : cout << "no\n";
    }
}
