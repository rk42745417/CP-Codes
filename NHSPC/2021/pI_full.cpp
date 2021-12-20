// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

struct mat : vector<vector<ll>> {
	mat(): vector<vector<ll>>(4, vector<ll>(4)) {

	}
	friend mat operator*(const auto &a, const auto &b) {
		mat res;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				for(int k = 0; k < 4; k++)
					res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
		return res;
	}
};

signed main() {
	ll n;
	cin >> n;
	mat res;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			res[i][j] = i == j;
	vector<vector<ll>> owo = {
		{0, 2, -1, 1},
		{0, 1, 1, 2},
		{0, 0, 1, 1},
		{1, 0, 0, 0}
	};
	mat a;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			a[i][j] = owo[i][j];
	n--;
	while(n) {
		if(n & 1)
			res = res * a;
		n >>= 1;
		a = a * a;
	}
	cout << res[0][3] << '\n';
}
