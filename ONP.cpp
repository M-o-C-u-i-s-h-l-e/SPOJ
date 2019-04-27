#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> m;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['^'] = 3;

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                cout << str[i];
                continue;
            }
            if (str[i] != ')') {
                st.push(str[i]);
                continue;
            } else {
                while (st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        cout << endl;
    }
}
