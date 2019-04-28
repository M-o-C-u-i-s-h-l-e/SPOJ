#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[107][107], sum[107][107];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i][i];
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i <= n-l; i++) {
				int j = i + l - 1;
				sum[i][j] = INT_MAX;
				for (int k = i; k < j; k++) {
					int temp = sum[i][k] + sum[k+1][j] + arr[i][k] * arr[k+1][j];
					if (temp < sum[i][j]) {
						sum[i][j] = temp;
						arr[i][j] = (arr[i][k] + arr[k+1][j]) % 100;
					}
				}
			}
		}
		cout << sum[0][n-1] << endl;
	}
}
