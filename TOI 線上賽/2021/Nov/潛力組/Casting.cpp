// 100/100
// 00:11:55
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(auto &a : arr)
		for(auto &b : a)
			cin >> b;
	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		bool ok = 1;
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if((i >> j & 1) && (i >> k & 1) && arr[j][k])
					ok = 0;
		if(ok)
			ans = max(ans, __builtin_popcount(i));
	}
	cout << ans << '\n';
}
