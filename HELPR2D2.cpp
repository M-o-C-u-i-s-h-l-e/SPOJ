#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define Max first
#define Min second

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

int update(vector<pair<int, int>> &segTree, int low, int high, int val, int pos) {
    if (val > segTree[pos].Max)
        return -1;
    if (low == high) {
        segTree[pos].Max -= val;
        segTree[pos].Min -= val;
        return low;
    }
    int mid = (low + high) >> 1;
    int temp = update(segTree, low, mid, val, 2 * pos + 1);
    if (temp == -1)
        temp = update(segTree, mid + 1, high, val, 2 * pos + 2);
    segTree[pos].Max = max(segTree[2 * pos + 1].Max, segTree[2 * pos + 2].Max);
    segTree[pos].Min = min(segTree[2 * pos + 1].Min, segTree[2 * pos + 2].Min);
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
        vector<pair<int, int>> segTree(N << 1, {k, k});
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
                int temp = update(segTree, 0, N - 1, val, 0);
                res = max(res, temp);
            }
        }
        cout << res + 1 << ' ' << (k * res - waste + k) << endl;
    }
}
