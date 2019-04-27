#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        stack<long long> st;
        long long i = 0, Max = 0;
        while (i < n) {
            if (st.empty() || v[st.top()] <= v[i])
                st.push(i++);
            else {
                long long x = st.top();
                st.pop();
                long long temp = v[x] * (st.empty() ? i : i - st.top() - 1);
                Max = max(temp, Max);
            }
        }
        while (!st.empty()) {
            long long x = st.top();
            st.pop();
            long long temp = v[x] * (st.empty() ? i : i - st.top() - 1);
            Max = max(Max, temp);
        }
        cout << Max << endl;
    }
}
