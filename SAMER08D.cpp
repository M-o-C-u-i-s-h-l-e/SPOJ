#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 1007

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int arr[N][N], Count[N][N];
    for (int i = 0; i <= N; i++)
    	arr[i][0] = 0, arr[0][i] = 0;
    Count[0][0] = 0;
    int k;
    cin >> k;
    while (k) {
    	string s1, s2;
    	cin >> s1 >> s2;
    	int n = s1.size(), m = s2.size();
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
    			Count[i][j] = (s1[i-1] == s2[j-1]) ? Count[i-1][j-1] + 1 : 0;
    			if (Count[i][j] >= k)
    				for (int z = k; z <= Count[i][j]; z++)
    					arr[i][j] = max(arr[i][j], arr[i-z][j-z] + z);
    		}
    	}
    	cout << arr[n][m] << endl;
    	cin >> k;
    }
}
