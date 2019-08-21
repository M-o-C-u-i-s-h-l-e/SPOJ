#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int toInt(string str) {
    stringstream ss(str);
    int x;
    ss >> x;
    return x;
}

int nextPowerOf2(int n) {
    int x = 1;
    while (x < n)
        x <<= 1;
    return x;
}

int update(vector<int> &segTree, int low, int high, int val, int pos) {
    if (val > segTree[pos])
        return -1;
    if (low == high) {
        segTree[pos] -= val;
        return low;
    }
    int mid = (low + high) >> 1;
    int temp = update(segTree, low, mid, val, 2 * pos + 1);
    if (temp == -1)
        temp = update(segTree, mid + 1, high, val, 2 * pos + 2);
    segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    return temp;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        int N = nextPowerOf2(n);
        vector<int> segTree(N << 1, k);
        int waste = 0, no, res = 0;
        for (int i = 0; i < n; i+=no) {
            string str;
            int val;
            cin >> str;
            if (str[0] == 'b') {
                cin >> no >> val;
            } else {
                no = 1;
                val = toInt(str);
            }
            for (int j = 0; j < no; j++) {
                waste += val;
                int temp = update(segTree, 0, n - 1, val, 0);
                res = max(res, temp);
            }
        }
        cout << res + 1 << ' ' << (k * res - waste + k) << endl;
    }
}
