#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    int x = 1;
    while (cin >> str) {
        if (str[0] == '-')
            break;
        int Count = 0, ans = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '{') {
                Count++;
            } else {
                if (Count == 0) {
                    Count++;
                    ans++;
                } else {
                    Count--;
                }
            }
        }
        cout << x++ << ". " << ans + Count / 2 << endl;
    }
}
