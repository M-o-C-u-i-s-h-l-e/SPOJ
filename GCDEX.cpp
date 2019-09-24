//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1000001

vector<int> phi(MAX);
vector<long> P(MAX);

void eulerTotient() {
	for (int i = 1; i < MAX; i++)
		phi[i] = i;
	for (int i = 2; i < MAX; i++) {
		if (phi[i] == i) {
			phi[i] = i - 1;
			for (int j = i << 1; j < MAX; j += i)
				phi[j] = (phi[j] / i) * (i - 1);
		}
	}
}

void pillaiArithmeticFunction() {
	for (int i = 1; i < MAX; i++)
		P[i] = 0;
	for (int i = 1; i < MAX; i++)
	    for (int j = i << 1; j < MAX; j += i)
	        P[j] += (i * phi[j / i]);
	for (int i = 1; i < MAX; i++)
	    P[i] += P[i - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	eulerTotient();
	pillaiArithmeticFunction();
	
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		cout << P[n] << endl;
	}
}
