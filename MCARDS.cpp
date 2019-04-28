#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int c, n, Min = INT_MAX, ord[4] = {1, 2, 3, 4};
int idx[5][101], C[407], V[407], seq[407], aux[407];

int lis() {
	int pos = 0;
	aux[pos++] = 0;
	for (int i = 1; i < c*n; i++) {
		if (seq[aux[pos-1]] < seq[i]) {
			aux[pos++] = i;
			continue;
		}
		int l = 0, r = pos-1;
		while (l < r) {
			int m = (l + r) / 2;
			(seq[aux[m]] < seq[i]) ? l = m+1 : r = m;
		}
		if (seq[i] < seq[aux[l]])
			aux[l] = i;
	}
	return pos;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> c >> n;
	for (int i = 0; i < c*n; i++)
		cin >> C[i] >> V[i];
	do {
		int Count = 0;
		for (int i = 0; i < c; i++)
			for (int j = 1; j <= n; j++)
				idx[ord[i]][j] = ++Count;
		for (int i = 0; i < c*n; i++)
			seq[i] = idx[C[i]][V[i]];
		Min = min(Min, (c*n) - lis());
	} while (next_permutation(ord, ord + c));
	cout << Min << endl;
}
