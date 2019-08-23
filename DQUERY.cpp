#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n;
	vector<int> v(n+1), arr(1e6+7, 0);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	cin >> q;
	vector<pair<int, pair<int, int>>> Q(q);
	vector<int> res(q);
	for (int i = 0; i < q; i++) {
		cin >> Q[i].S.F >> Q[i].S.S;
		Q[i].F = i;
	}
	int blockSz = ceil(sqrt(n));
	sort(Q.begin(), Q.end(), [&](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		int t1 = a.S.F / blockSz;
		int t2 = b.S.F / blockSz;
		if (t1 != t2)
			return t1 < t2;
		return a.S.S < b.S.S;
	});
	int st = 0, end = 0;
	int Count = 0;
	for (int i = 0; i < q; i++) {
		while (st < Q[i].S.F) {
			arr[v[st]]--;
			if (arr[v[st++]] == 0)
				Count--;
		}
		while (end > Q[i].S.S) {
			arr[v[end]]--;
			if (arr[v[end--]] == 0)
				Count--;
		}
		while (st > Q[i].S.F) {
			arr[v[--st]]++;
			if (arr[v[st]] == 1)
				Count++;
		}
		while (end < Q[i].S.S) {
			arr[v[++end]]++;
			if (arr[v[end]] == 1)
				Count++;
		}
		res[Q[i].F] = Count;
	}
	for (int i = 0; i < q; i++)
		cout << res[i] << endl;
}
