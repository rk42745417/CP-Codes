/*
SUM
100/100
00:32:59
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+9;

void mul(vector<vector<int>> &a, const vector<vector<int>> &b) {
	auto x = a;
	for(int i = 0; i < x.size(); i++) {
		for(int j = 0; j < x[i].size(); j++) {
			x[i][j] = 0;
			for(int k = 0; k < x.size(); k++) {
				x[i][j] = (x[i][j] + a[i][k]*b[k][j]) % MOD;
			}
		}
	}
	a = x;
}
int cal(int a, int b, int n) {
	n-=2;
	vector<vector<int>> res = {
		{a, b, 0},
		{1, 0, 0},
		{a, b, 1}
	};
	vector<vector<int>> init = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	while(n) {
		if(n&1)
			mul(init, res);
		mul(res, res);

		n>>=1;
	}
	return (2+init[2][0]+init[2][1])%MOD;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, l, r;
	cin >> a >> b >> l >> r;
	cout << (cal(a, b, r)+MOD-cal(a, b, l-1))%MOD;

	return 0;
}
