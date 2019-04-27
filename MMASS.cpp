#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> m;
    m['C'] = 12;
    m['H'] = 1;
    m['O'] = 16;

    string str, s = "";
    cin >> str;
    stack<int> st;
    int total = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            int v = st.top();
            st.pop();
            st.push(v * (str[i] - '0'));
        } else if (isalpha(str[i])) {
            st.push(m[str[i]]);
        } else if (str[i] == '(') {
            st.push(-1);
        } else {
            int v = 0;
            while (st.top() != -1) {
                v += st.top();
                st.pop();
            }
            st.pop();
            st.push(v);
        }
    }
    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    cout << total << endl;
}
