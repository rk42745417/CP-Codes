// 63.589/100
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

signed main() {
	ll k;
	cin >> k;
	const int n = __lg(k) + 1, m = __lg(k) + 2;
	vector<string> arr(n, string(m, '.'));
	for(int i = 0; i + 1 < n; i++) {
		arr[i][i + 1] = 'X';
		arr[i][i + 2] = 'd';
		arr[i + 1][i + 1] = 'r';
	}
	for(int i = 0; i < n; i++) {
		//cout << k << ' ' << (k >> (n - i)) << '\n';
		if(k >> (n - i - 1) & 1) {
			if((k & -k) >> (n - i - 1) & 1)
				arr[i][0] = 'r';
			else
				arr[i][0] = 'X';
		}
		else
			arr[i][0] = 'd';
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == '.')
				arr[i][j] = 'r';
	for(int i = 0; i < n; i++)
		arr[i][m - 1] = 'd';
	for(int i = 0; i < m; i++)
		arr[n - 1][i] = 'r';
	arr[n - 1][m - 1] = '.';
	cout << n << ' ' << m << '\n';
	for(const auto &s : arr)
		cout << s << '\n';
}
