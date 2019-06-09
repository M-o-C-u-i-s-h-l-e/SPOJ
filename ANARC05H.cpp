#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string str;

long long solve(int left, int start, int end, int sum) {
	int total = 0, right = sum;
	long long Count = 0;
	for (int i = start; i <= end; i++) {
		total += (str[i] - '0');
		right -= (str[i] - '0');
		if (i == end && total >= left)
			Count++;
		else if (total >= left && total <= right)
			Count += solve(total, i+1, end, right);
	}
	return Count;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (cin >> str) {
		if (str == "bye")
			break;
		int n = str.size();
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += (str[i] - '0');
		cout << t++ << ". " << solve(0, 0, n-1, sum) << endl;
	}
}
