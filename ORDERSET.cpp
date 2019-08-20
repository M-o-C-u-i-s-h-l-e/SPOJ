#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl '\n'
#define orderedSet tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    orderedSet s;
    int q;
    cin >> q;
    while (q--) {
        char c;
        long x;
        cin >> c >> x;
        if (c == 'I') {
            s.insert(x);
        } else if (c == 'D') {
            s.erase(x);
        } else if (c == 'K') {
            (x > s.size()) ? cout << "invalid\n" : cout << *s.find_by_order(x - 1) << endl;
        } else {
            cout << s.order_of_key(x) << endl;
        }
    }
}
