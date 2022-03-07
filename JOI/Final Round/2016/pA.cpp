// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<ll> dp(n + 1, LINF);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int mx = 0, mn = INF;
		for(int j = i; j > max(0, i - m); j--) {
			mx = max(mx, arr[j]);
			mn = min(mn, arr[j]);
			dp[i] = min(dp[i], dp[j - 1] + k + ll(i - j + 1) * (mx - mn));
		}
	}
	cout << dp[n] << '\n';
}
