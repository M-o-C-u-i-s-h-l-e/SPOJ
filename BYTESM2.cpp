#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int arr[n][m], ans[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		for (int i = 0; i < m; i++)
			ans[0][i] = arr[0][i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = arr[i][j];
				if (j == 0) {
					ans[i][j] += max(ans[i-1][j], ans[i-1][j+1]);
				} else if (j == m-1) {
					ans[i][j] += max(ans[i-1][j], ans[i-1][j-1]);
				} else {
					ans[i][j] += max(ans[i-1][j], max(ans[i-1][j-1], ans[i-1][j+1]));
				}
			}
		}
		cout << *max_element(ans[n-1], ans[n-1] + m) << endl;
	}
}
	
