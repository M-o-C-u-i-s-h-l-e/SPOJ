#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string s1, s2;
int n, m;
bool v1[107], v2[107];
int arr[107][107];

void pre() {
	fill(v1, v1 + n, false);
	fill(v2, v2 + m, false);
	for (int i = 0; i <= n; i++)
		arr[i][0] = 0;
	for (int i = 0; i <= m; i++)
		arr[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i-1] == s2[j-1])
				arr[i][j] = arr[i-1][j-1] + 1;
			else
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
		}
	}
	int x = n, y = m;
	while (x > 0 && y > 0) {
		if (s1[x-1] == s2[y-1]) {
			v1[x-1] = true;
			v2[y-1] = true;
			x--, y--;
		}
		else
			(arr[x-1][y] >= arr[x][y-1]) ? x-- : y--;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	while (cin >> s1) {
		cin >> s2;
		string res = "";
		n = s1.size(), m = s2.size();
		pre();
		int i = 0, j = 0;
		while (i < n && j < m) {
			int k = i, l = j;
			for ( ; k < n && !v1[k]; k++)
				res += s1[k];
			for ( ; l < m && !v2[l]; l++)
				res += s2[l];
			while (k < n && l < m && v1[k] && v2[l] && s1[k] == s2[l]) {
				res += s1[k];
				k++, l++;
			}
			i = k;
			j = l;
		}
		while (i < n)
			res += s1[i++];
		while (j < m)
			res += s2[j++];
		cout << res << endl;
	}
}
