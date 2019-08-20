#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<long> input(1e6 + 7);
vector<long> segTree(1e6 + 7);

void build(int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = input[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] & segTree[2 * pos + 2];
}

long query(int low, int high, int pos, int qLow, int qHigh) {
    if (low >= qLow && high <= qHigh)
        return segTree[pos];
    if (low > qHigh || high < qLow)
        return 8589934591;
    int mid = (low + high) >> 1;
    int n1 = query(low, mid, 2 * pos + 1, qLow, qHigh);
    int n2 = query(mid + 1, high, 2 * pos + 2, qLow, qHigh);
    return n1 & n2;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        long n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> input[i];
        if (2 * k >= n) {
            long res = 8589934591;
            for (int i = 0; i < n; i++)
                res &= input[i];
            for (int i = 0; i < n; i++)
                cout << res << ' ';
        } else {
            build(0, n - 1, 0);
            for (int i = 0; i < n; i++) {
                int l = ((i - k) % n + n) % n;
                int r = ((i + k) % n + n) % n;
                if (l <= r) {
                    cout << query(0, n - 1, 0, l, r) << ' ';
                } else {
                    cout << (query(0, n - 1, 0, l, n - 1) & query(0, n - 1, 0, 0, r)) << ' ';
                }
            }
        }
        cout << endl;
    }
}
