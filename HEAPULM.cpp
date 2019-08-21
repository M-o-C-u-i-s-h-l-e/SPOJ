#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define F first
#define S second

int nextPowerOf2(int n) {
    int x = 1;
    while (x < n)
        x <<= 1;
    return x;
}

void build(vector<int> &segTree, vector<pair<string, int>> &input, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = low;
        return;
    }
    int mid = (low + high) >> 1;
    build(segTree, input, low, mid, 2 * pos + 1);
    build(segTree, input, mid + 1, high, 2 * pos + 2);
    segTree[pos] = (input[segTree[2 * pos + 1]].S >= input[segTree[2 * pos + 2]].S) ? segTree[2 * pos + 1] : segTree[2 * pos + 2];
}

int query(vector<int> &segTree, vector<pair<string, int>> &input, int low, int high, int qLow, int qHigh, int pos) {
    if (low >= qLow && high <= qHigh)
        return segTree[pos];
    if (high < qLow || low > qHigh)
        return -1;
    int mid = (low + high) >> 1;
    int n1 = query(segTree, input, low, mid, qLow, qHigh, 2 * pos + 1);
    int n2 = query(segTree, input, mid + 1, high, qLow, qHigh, 2 * pos + 2);
    if (n1 == -1)
        return n2;
    if (n2 == -1)
        return n1;
    return (input[n1].S >= input[n2].S) ? n1 : n2;
}

void print(vector<int> &segTree, vector<pair<string, int>> &input, int low, int high) {
    if (low <= high) {
        int cur = query(segTree, input, 0, input.size()-1, low, high, 0);
        cout << '(';
        print(segTree, input, low, cur - 1);
        cout << input[cur].F << '/' << input[cur].S;
        print(segTree, input, cur + 1, high);
        cout << ')';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string str;
    while (cin >> n) {
        if (n == 0)
            break;
        vector<pair<string, int>> v(n, {"", 0});
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '/') {
                    continue;
                } else if (isdigit(str[j])) {
                    v[i].S = (v[i].S << 3) + (v[i].S << 1) + (str[j] - '0');
                } else {
                    v[i].F += str[j];
                }
            }
        }
        sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.F < b.F;
        });
        int N = nextPowerOf2(n);
        vector<int> segTree(N << 1);
        build(segTree, v, 0, n-1, 0);
        print(segTree, v, 0, n-1);
        cout << endl;
    }
}
